#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_CLIENTS 128
#define BUFFER_SIZE 200000

typedef struct client_s
{
    int socket;
    int id;
}   client_t;

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "Wrong number of arguments\n", argv[0]);
    exit(1);
  }

  client_t clients[MAX_CLIENTS];
  int next_id = 0;
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  fd_set activeSockets;
  
  if (serverSocket < 0)
  {
    perror("Error creating server socket");
    exit(1);
  }

  struct sockaddr_in serverAddress = {0};
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  serverAddress.sin_port = htons(atoi(argv[1]));

  if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
  {
    perror("Error binding on server socket");
    exit(1);
  }

  if (listen(serverSocket, MAX_CLIENTS) < 0)
  {
    perror("Error listening on server socket");
    exit(1);
  }

  FD_ZERO(&activeSockets);
  FD_SET(serverSocket, &activeSockets);

  int maxSocket = serverSocket;
  
  while (1)
  {
    fd_set readySockets = activeSockets;
    if (select(maxSocket + 1, &readySockets, NULL, NULL, NULL) < 0)
    {
      perror("Error in select");
      exit(1);
    }

    for (int socketId = 0; socketId <= maxSocket; socketId++)
    {
      if (FD_ISSET(socketId, &readySockets))
      {
        char buffer[BUFFER_SIZE];
        bzero(buffer, BUFFER_SIZE);
        if (socketId == serverSocket)
        {
          int clientSocket = accept(serverSocket, NULL, NULL);
          if (clientSocket < 0)
          {
            perror("Error accepting client connextion");
            exit(1);
          }

          FD_SET(clientSocket, &activeSockets);
          maxSocket = (clientSocket > maxSocket) ? clientSocket : maxSocket;
          clients[next_id].socket = clientSocket;
          clients[next_id].id = next_id;
          next_id++;

          sprintf(buffer, "server: client %d just arrived\n", next_id);
          for (int i = 0; i < next_id; i++)
          {
            send(clients[i].socket, buffer, strlen(buffer), 0);
          }
        }
        else 
        {
          int bytesRead = recv(socketId, buffer, sizeof(buffer) - 1, 0);
          printf("%s\n", buffer);

          if (bytesRead <= 0)
          {
            sprintf(buffer, "server: client %d just left\n", socketId);
            
            for (int i = 0; i < next_id; i++)
            {
              if (clients[i].socket != socketId)
                send(clients[i].socket, buffer, strlen(buffer), 0);
            }
            close(socketId);
            FD_CLR(socketId, &activeSockets);
          }
          else 
          {
            char message[BUFFER_SIZE];
            bzero(message, BUFFER_SIZE);
            sprintf(message, "client %d: %s\n", socketId, buffer);

            for (int i = 0; i < next_id; i++)
            {
              if (clients[i].socket != socketId)
                send(clients[i].socket, message, strlen(message), 0);
            }
          }
        }
      }
    }
  }

  return (0);
}
