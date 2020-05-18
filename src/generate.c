#include <stdlib.h>
#include <gmp.h>
#include <time.h>

#include "structure.h"
#include "generate.h"

key *init_key(void) {
    key *k = malloc(sizeof(key));
    k->pr = malloc(sizeof(private));
    k->pu = malloc(sizeof(public));
    mpz_inits(k->pr->d, k->pr->n, k->pu->e, k->pu->n, NULL);
    return k;
}

void clear_key(key *k) {
    mpz_clears(k->pr->d, k->pr->n, k->pu->e, k->pu->n, NULL);
    free(k->pr);
    free(k->pu);
    free(k);
}

void next_prime(mpz_t p, int size) {
    gmp_randstate_t etat ;
    gmp_randinit_default(etat);
    gmp_randseed_ui(etat, time(NULL));

    mpz_urandomb(p, etat, size);
    mpz_nextprime(p, p);

    gmp_randclear(etat);
}

void euclide(mpz_t u, mpz_t v, mpz_t phi_n, mpz_t e) {
    mpz_t q, r, rp rs, up, us, vp, vs;
    mpz_inits(q, r, rp, up, us, vp, vs, NULL);

    // Init
    mpz_set(r, phi_n);
    mpz_set(rp, e);
    mpz_set_ui(u, 1);
    mpz_set_ui(v, 0);
    mpz_set_ui(up, 0);
    mpz_set_ui(vp, 1);

    // loop
    while(mpz_cmp_ui(rp, 0) != 0) {
        mpz_div(q, r, rp);
        mpz_set(rs, r); mpz_set(us, u); mpz_set(vs, v);
        mpz_set(r, rp); mpz_set(u, up); mpz_set(v, vp);
    }

    mpz_clears(q, r, rp, up, us, vp, vs, NULL);
}

void compute_e(key *k, mpz_t phi_n) {
    mpz_t test;
    mpz_init(test);

    mpz_set_ui(test, 1);

    mpz_t tmp;
    mpz_init(tmp);

    for(int i = 1; i < 99999; i++) {
        mpz_mul_2exp(k->pu->e, test, i);
        mpz_gcd(tmp, phi_n, k->pu->e);
        if(mpz_cmp_ui(tmp, 1) == 0) {
            break;
        }
    }

    mpz_clear(tmp);
    mpz_clear(test);
}

void compute_d(key *k, mpz_t phi_n) {
    mpz_t u, v;
    mpz_inits(u, v, NULL);
    euclide(u, v, phi_n, k->pu->e);
    mpz_set(k->pr->d, v);
    mpz_clears(u, v, NULL);
}

key *generate(int size_modulus) {
    key *k = init_key();

    mpz_t p, q, phi_n;
    mpz_inits(p, q, phi_n, NULL);

    // generate 2 prime
    do {
        next_prime(p, size_modulus / 2);
        next_prime(q, size_modulus / 2);
    } while (mpz_probab_prime_p(p, size_modulus / 20) != 1 && mpz_probab_prime_p(q, size_modulus / 20) != 1 );

    // Set n
    mpz_mul(k->pr->n, p, q);
    mpz_set(k->pu->n, k->pr->n);

    // Compute phi_n
    mpz_t p1, q1;
    mpz_inits(p1, q1, NULL);
    mpz_sub_ui(p1, p, 1);
    mpz_sub_ui(q1, q, 1);
    mpz_mul(phi_n, q1, p1);
    mpz_clears(p1, q1, NULL);

    // Compute e

    // Compute d

    mpz_clears(p, q, phi_n, NULL);

    return k;
}