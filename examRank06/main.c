#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>

#define MAX_CLIENT 128

int	error(char *str)
{
	fprintf(stderr, "%s\n", str);
	return (1);
}

int	main(int argc, char **argv)
{
	int			clientSocket[MAX_CLIENT];
	int			serverSocket;
	struct sockaddr_in	hints;
	struct addrinfo		serv_info;

	if (argc != 2)
		return (error("Wrong number of arguments"));

	memset(&hints, 0, sizeohints;
	hints.sin_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if (getaddrinfo(NULL, argv[1], &hints, &serv_info) < 0)
		return (error("Fatal error"));

	serverSocket = socket(AF_INET, SOCK_STREAM, AI_PASSIVE);
	if (serverSocket == -1)
		return (error("Fatal error"));

	if (bind(serverSocket, serv_info.ai_addr, serv_info.ai_addrlen) < 0)
		return (error("Fatal error"));
	if (listen(serverSocket, MAX_CLIENT) < 0)
		return (error("Fatal error"));
}
