#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>


int parse_arguments(int argc, char *argv[], char **host, char **filename, char** localfile, char **port);
void print_address(struct addrinfo *addr);