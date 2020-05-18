#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#include "display.h"

void print_mpz(mpz_t m, const char* name, int base) {
    printf("%s : ", name);
    mpz_out_str(0, base, m);
    printf("\n\n");
}

void print_bold(const char *s) {
    printf("\033[1m");
    printf("%s", s);
    printf("\033[0m");
}