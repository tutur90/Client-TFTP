#include "header.h"


int main(int argc, char *argv[]) {
    char *host, *filename, *localfile, *ip;
    
    if(parse_arguments(argc, argv, &host, &filename, &localfile, &ip) == EXIT_FAILURE){
        return EXIT_FAILURE;
    }

    struct addrinfo hints, *result, *p;
    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_family = AF_UNSPEC;    // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // Stream socket

    int status = getaddrinfo(host, port, &hints, &result);
    if (status != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_family = AF_UNSPEC;    // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // Stream socket

    int status = getaddrinfo(host, port, &hints, &result);
    if (status != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}