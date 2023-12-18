#include "header.h"


// Function to create a socket using the information from the addrinfo structure
int create_socket(struct addrinfo *result) {
    int sockfd = -1;

    // Check if the addrinfo structure is not NULL
    if (result != NULL) {
        // Create a socket using the information from the addrinfo structure
        sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

        // Check if socket creation failed
        if (sockfd < 0) {
            perror("Failed to create socket\n");
        }
    }

    return sockfd; 
}
