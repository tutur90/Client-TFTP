#include "header.h"


int main(int argc, char *argv[]) {
    char *host, *filename, *local_file, *port;
    
    if(parse_arguments(argc, argv, &host, &filename, &local_file, &port) == EXIT_FAILURE){
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

    request[0] = 0x00; // Opcode RRQ
    request[1] = 0x01; // Opcode  RRQ
    strcpy(&request[2], filename);
    strcpy(&request[strlen(filename) + 2], "octet");
    request[strlen(file) + 3 + strlen("octet") + 1] = 0x00; // Null byte to end the RRQ packet

    int request_len = strlen(filename) + 3 + strlen("octet");
    request[request_len] = 0x00;


    if (sendto(sockfd, request, request_len, 0, server_addr, addr_len) == -1) {
        perror("Error sending RRQ packet");
        close(sockfd);
        exit(EXIT_FAILURE); 
    }


    printf("RRQ packet sent successfully.\n");

    // Receive 
    char buffer[MAX_BUFFER_SIZE];

    ssize_t bytes_received;

    // Réception du paquet de données
    bytes_received = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, NULL, NULL);
    if (bytes_received == -1) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);

    }
    
    // Extrait le contenu du fichier
    FILE *file = fopen(local_file, "wb");
    if (file == NULL) {
        perror("Error opening local file");
        exit(EXIT_FAILURE);
    }

    fwrite(buffer + 4, 1, bytes_received - 4, file);
    
    fclose(file);

    // Envoi de l'accusé de réception (ACK)
    uint16_t block_number = ntohs(*(uint16_t *)(buffer + 2));
    uint8_t ack_packet[4] = {0, 4, block_number / 256, block_number % 256};
    if (sendto(sockfd, ack_packet, sizeof(ack_packet), 0, server_addr, addr_len) == -1) {
        perror("Error sending ACK");
            exit(EXIT_FAILURE);
    }

    printf("ACK recieved\n");

    // Free memory allocated for address info
    freeaddrinfo(result);
    // Close Socket
    close(sockfd);

    return EXIT_SUCCESS;
}
