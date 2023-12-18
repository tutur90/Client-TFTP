#include "header.h"


int create_socket(struct addrinfo *result) {
    int sockfd = -1;
    // Iterate through available address info results to create a socket
    if (result != NULL) {
        // Create a socket based on the address info
        sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

        if (sockfd == -1) {
        perror("socket");
        } else {

        // If socket creation fails, set sockfd to 0 
        sockfd = 0;
        }
    }

    // Check if socket creation failed
    if (sockfd == -1) {
        fprintf(stderr, "Failed to create socket\n");
        return 3;
    }

    return sockfd;
}

