#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENT 128
#define BUFFER_SIZE 200000

typedef struct client_s
{
  int id;
  int socket;
} client_t;

int get_id(client_t *clients, int socket, int nbr_client)
{
  for (int i = 0; i < nbr_client; i++)
  {
    if (clients[i].socket == socket)
      return (clients[i].id);
  }
  return (-1);
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    write(2, "Wrong number of arguments\n", 26);
    exit(1);
  }

  client_t *clients = NULL;
  int nbr_client = 0;
  int next_id = 0;
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  fd_set activeSockets;

  if (serverSocket < 0)
  {
    write(2, "Fatal error\n", 12);
    exit(1);
  }

  struct sockaddr_in serverAddr = {0};
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  serverAddr.sin_port = htonl(atoi(argv[1]));

  if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
  {
    write(2, "Fatal error\n", 12);
    exit(1);
  }

  if (listen(serverSocket, MAX_CLIENT) < 0)
  {
    write(2, "Fatal error\n", 12);
    exit(1);
  }

  FD_ZERO(&activeSockets);
  FD_SET(serverSocket, &activeSockets);

  int maxSocket = serverSocket;

  while(1)
  {
    printf("test\n");
    fd_set readySockets = activeSockets;
    if (select(maxSocket + 1, &readySockets, NULL, NULL, NULL) < 0)
    {
      write(2, "Fatal error\n", 12);
      exit(1);
    }
    printf("test\n");

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
            write(2, "Fatal error\n", 12);
            exit(1);
          }
          FD_SET(clientSocket, &activeSockets);
          maxSocket = (clientSocket > maxSocket) ? clientSocket : maxSocket;
          nbr_client++;

          client_t *tmp = calloc(nbr_client + 1, sizeof(client_t));
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
          continue;
        }
      }
    }
  }

  return (0);
}
