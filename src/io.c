#include <stdio.h>

#include "structure.h"
#include "generate.h"
#include "io.h"

void write_key(key *k) {
    char *path = "features/key.txt";
    FILE *f = fopen(path, "w");
    mpz_out_str(f, 2, k->pu->n);
    fprintf(f, "\n");
    mpz_out_str(f, 2, k->pu->e);
    fprintf(f, "\n");
    mpz_out_str(f, 2, k->pr->d);
    fprintf(f, "\n");
    fclose(f);
}

key *read_key(void) {
    key *k = init_key();
    char *path = "features/key.txt";
    FILE *f = fopen(path, "r");
    mpz_inp_str(k->pu->n, f, 2);
    fgetc(f);
    mpz_set(k->pr->n, k->pu->n);
    mpz_inp_str(k->pu->e, f, 2);
    fgetc(f);
    mpz_inp_str(k->pr->d, f, 2);
    fgetc(f);
    fclose(f);
    return k;
}