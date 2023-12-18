#include "header.h"


int main(int argc, char *argv[]) {
    char *host, *filename, *localfile, *port;
    
    if(parse_arguments(argc, argv, &host, &filename, &localfile, &port) == EXIT_FAILURE){
        return EXIT_FAILURE;
    }

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_family = AF_INET;    // IPv4 adress
    hints.ai_socktype = SOCK_DGRAM; // Datagram socket for UDP

    int status = getaddrinfo(host, port, &hints, &result);
    if (status != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

        // Print the resolved addresses
    for (struct addrinfo *addr = result; addr != NULL; addr = addr->ai_next) {
        print_address(addr);
    }

    // Create a socket based on the address info
    int sockfd = create_socket(result);

    if(sockfd < 0){
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

        // Construct RRQ packet
    char request[MAX_BUFFER_SIZE];
    struct sockaddr *server_addr = result->ai_addr;
    socklen_t addr_len = result->ai_addrlen;


    memset(request, 0, MAX_BUFFER_SIZE);



    request[0] = 0x00;


    request[1] = 0x01;
    strcpy(&request[2], filename);
    request[strlen(filename) + 3] = 0x00;
    strcpy(&request[strlen(filename) + 4], "octet");
    int request_len = strlen(filename) + 5 + strlen("octet");
    request[request_len] = 0x00;


    if (sendto(sockfd, request, request_len, 0, server_addr, addr_len) == -1) {
        perror("Error sending RRQ packet");
        close(sockfd);
        exit(EXIT_FAILURE); 
    }


    printf("RRQ packet sent successfully.\n");

    // Free memory allocated for address info
    freeaddrinfo(result);
    // Close Socket
    close(sockfd);

    return EXIT_SUCCESS;
}
