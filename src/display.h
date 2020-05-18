#ifndef _display_h
#define _display_h

#include <gmp.h>

/**
 * Print a mpz on stdout
 * @param m : mpz
 * @param name : name of mpz to print
 * @param base : base to print
 */
void print_mpz(mpz_t m, const char* name, int base);

/**
 * Print a bold string on stdout
 * @param s : string
 */
void print_bold(const char *s);

#endif // !_display_h