#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_BUFFER_SIZE 1024


int parse_arguments(int argc, char *argv[], char **host, char **filename, char** localfile, char **port);
void print_address(struct addrinfo *addr);
int create_socket(struct addrinfo *result);