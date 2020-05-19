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

typedef struct {
    mpz_t text;
    mpz_t size;
} msg;

/**
 * Init key
 */
key *init_key(void);

/**
 * Clear key
 */
void clear_key(key *k);

msg *init_msg(void);

void clear_msg(msg *m);

#endif // !_structure_h