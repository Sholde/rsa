#ifndef _structure_h
#define _structure_h

#include <gmp.h>

typedef struct {
    mpz_t n;
    mpz_t e;
} public;

typedef struct {
    mpz_t n;
    mpz_t d;
} private;

typedef struct {
    public *pu;
    private *pr;
} key;

#endif // !_structure_h