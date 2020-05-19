#include <stdlib.h>

#include "structure.h"

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

msg *init_msg(void) {
    msg *m = malloc(sizeof(msg));
    mpz_inits(m->text, m->size, NULL);
    return m;
}

void clear_msg(msg *m) {
    mpz_clears(m->text, m->size, NULL);
    free(m);
}