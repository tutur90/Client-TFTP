#include "header.h"


int main(int argc, char *argv[]) {
    char *host, *filename, *localfile, *ip;
    
    if(parse_arguments(argc, argv, &host, &filename, &localfile, &ip) == EXIT_FAILURE){
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
}
