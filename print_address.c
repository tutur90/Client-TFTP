#include "header.h"

void print_address(struct addrinfo *addr) {
    void *addr_ptr;
    char addr_str[INET6_ADDRSTRLEN];

    if (addr->ai_family == AF_INET) {
        struct sockaddr_in *ipv4 = (struct sockaddr_in *)addr->ai_addr;
        addr_ptr = &(ipv4->sin_addr);
    } else {
        struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)addr->ai_addr;
        addr_ptr = &(ipv6->sin6_addr);
    }

    // Convert the IP address to a string
    inet_ntop(addr->ai_family, addr_ptr, addr_str, sizeof(addr_str));
    printf("Address: %s\n", addr_str);
}