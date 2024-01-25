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

int get_id(client_t *clients, int socket, int nbr_client)
{
  int id;

  for (int i = 0; i < nbr_client; i++)
  {
    if (clients[i].socket == socket)
      return (clients[i].id);
  }
  return (-1);
}

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "Wrong number of arguments\n", argv[0]);
    exit(1);
  }

  client_t *clients = NULL;
  int next_id = 0;
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  fd_set activeSockets;
  int nbr_client = 0;
  
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
          nbr_client++;
          maxSocket = (clientSocket > maxSocket) ? clientSocket : maxSocket;
          client_t *tmp = calloc(nbr_client + 1, sizeof(client_t *));
          for (int i = 0; i < nbr_client - 1; i++)
          {
            tmp[i].id = clients[i].id;
            tmp[i].socket = clients[i].socket;
          }
          tmp[nbr_client - 1].id = next_id;
          tmp[nbr_client - 1].socket = clientSocket;
          free(clients);
          clients = tmp;

          sprintf(buffer, "server: client %d just arrived\n", next_id);
          for (int i = 0; i < nbr_client; i++)
          {
            send(clients[i].socket, buffer, strlen(buffer), 0);
          }
          next_id++;
        }
        else 
        {
          int bytesRead = recv(socketId, buffer, sizeof(buffer) - 1, 0);
          int id = get_id(clients, socketId, nbr_client);

          if (bytesRead <= 0)
          {
            sprintf(buffer, "server: client %d just left\n", id);
            
            for (int i = 0; i < nbr_client; i++)
            {
              if (clients[i].socket != socketId)
                send(clients[i].socket, buffer, strlen(buffer), 0);
            }
            close(socketId);
            FD_CLR(socketId, &activeSockets);
            nbr_client--;
            client_t *tmp = calloc(nbr_client + 1, sizeof(client_t));
            for (int i = 0, j = 0; i < nbr_client + 1; i++)
            {
              if (clients[i].socket != socketId)
              {
                tmp[j].id = clients[i].id;
                tmp[j].socket = clients[i].socket;
                j++;
              }
            }
            free(clients);
            clients = tmp;
          }
          else 
          {
            char message[BUFFER_SIZE];
            bzero(message, BUFFER_SIZE);
            sprintf(message, "client %d: %s\n", id, buffer);

            for (int i = 0; i < nbr_client; i++)
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
