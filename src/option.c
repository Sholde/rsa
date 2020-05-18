#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "option.h"

void print_bold(const char *s) {
    printf("\033[1m");
    printf("%s", s);
    printf("\033[0m");
}

void option(int argc, char **argv) {
    if(argc > 2) {
        printf("Use the option --help\n");
    }
    else if (argc == 1) {
        printf("This executable does nothing.\n");
    }
    else if( strcmp(argv[1], "--version") == 0) {
        printf("comming soon\n");
    }
    else if( strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        print_bold("OPTION\n");
        print_bold("\t-h, --help\n");
        printf("\t\tdisplay this help\n");
        print_bold("\t--version\n");
        printf("\t\toutput version information\n");
    }
    else {
        printf("Use the option --help\n");
    }
}