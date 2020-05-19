#include <stdio.h>
#include <stdlib.h>

#include "structure.h"
#include "generate.h"
#include "io.h"

void write_key(key *k) {
    char *path = "features/key.txt";
    FILE *f = fopen(path, "w");

    if (f == NULL) {
        fputs("File error", stderr);
        exit(1);
    }

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

    if (f == NULL) {
        fputs("File error", stderr);
        exit(1);
    }
    
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

void write_file(char *path, char *s) {
    FILE *f = fopen(path, "w");

    if (f == NULL) {
        fputs("File error", stderr);
        exit(1);
    }
    
    fprintf(f, s);
    fclose(f);
}

char *read_file(char *path) {
    FILE *f = fopen(path, "r");
    long lSize;
    char * buffer;
    size_t result;

    if (f == NULL) {
        printf("1");
        fputs("File error", stderr);
        exit(1);
    }

    // obtain file size:
    fseek(f, 0, SEEK_END);
    lSize = ftell(f);
    rewind(f);

    // allocate memory to contain the whole file:
    buffer = malloc(sizeof(char) * lSize);
    if (buffer == NULL) {
        printf("2");
        fputs("Memory error", stderr);
        exit (2);
    }

    // copy the file into the buffer:
    result = fread(buffer, 1, lSize, f);
    if (result != lSize) {
        printf("3");
        fputs("Reading error", stderr);
        exit (3);
    }

    /* the whole file is now loaded in the memory buffer. */

    // terminate
    fclose(f);
    return buffer;
}