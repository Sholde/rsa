#include <stdio.h>

#include "option.h"
#include "structure.h"
#include "generate.h"

void print_mpz(mpz_t m, const char* name, int base) {
    printf("%s : ", name);
    mpz_out_str(0, base, m);
    printf("\n\n");
}

int main(int argc, char **argv) {
    //option(argc, argv);

    key *k = generate(2048);
    print_mpz(k->pr->n, "private n", 10);
    print_mpz(k->pr->d, "d", 10);
    print_mpz(k->pu->n, "public n", 10);
    print_mpz(k->pu->e, "e", 10);

    printf("Test : \n");
    mpz_t test;
    mpz_init(test);
    mpz_set_ui(test, 8);
    mpz_powm(test, test, k->pu->e, k->pu->n);
    print_mpz(test, "cypher", 10);
    mpz_powm(test, test, k->pr->d, k->pr->n);
    print_mpz(test, "decypher", 10);
    mpz_clear(test);
    printf("size of n : %ld\n", mpz_sizeinbase(k->pr->n, 2));

    clear_key(k);
    return 0;
}