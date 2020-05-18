#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#include "structure.h"
#include "generate.h"
#include "display.h"
#include "option.h"
#include "io.h"

void option(int argc, char **argv) {
    if(argc == 1) {
        printf("Use the option --help\n");
    }
    else if( strcmp(argv[1], "--version") == 0) {
        printf("comming soon\n");
    }
    else if( strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        print_bold("OPTION\n");
        print_bold("\t-g, --generate\n");
        printf("\t\tgenerate a key\n");
        print_bold("\t-h, --help\n");
        printf("\t\tdisplay this help\n");
        print_bold("\t-k, --key\n");
        printf("\t\tdisplay your key\n");
        print_bold("\t--version\n");
        printf("\t\toutput version information\n");
    }
    else if (strcmp(argv[1], "--generate") == 0 || strcmp(argv[1], "-g") == 0) {
        if( argc == 3 ) {
            int size = atoi(argv[2]);
            key *k = generate(size);
            write_key(k);
            clear_key(k);
        }
        else {
            printf("Please give a number for the modulus size\n");
            printf("Use the option --help\n");
        }
    }
    else if (strcmp(argv[1], "--key") == 0 || strcmp(argv[1], "-k") == 0) {
        key *k = read_key();
        print_mpz(k->pr->n, "n", 16);
        print_mpz(k->pr->d, "d", 16);
        print_mpz(k->pu->e, "e", 16);
        clear_key(k);
    }
    else {
        printf("Use the option --help\n");
    }
}