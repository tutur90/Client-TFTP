#include "header.h"

// Function to parse command line arguments
int parse_arguments(int argc, char *argv[], char **host, char **filename, char **localfile, char **port) {
    // Check if the number of arguments is not 4 or 5
    if (argc != 4 && argc != 5) {
        printf("Usage: %s <host> <file_name> <local_file> Optional: <Port>\n", argv[0]);
        return EXIT_FAILURE;  // Return failure status
    }

    // Allocate memory and copy the content of the command line arguments to the corresponding pointers
    *host = strdup(argv[1]);
    *filename = strdup(argv[2]);
    *localfile = strdup(argv[3]);

    // Check if a port number is provided as the fifth argument
    *port = (argc == 5) ? argv[4] : "69";  // Convert the string to an integer, use 69 if not provided

    return EXIT_SUCCESS;  // Return success status
}