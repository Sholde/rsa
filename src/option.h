#ifndef _option_h
#define _option_h

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

/**
 * Check option
 * @param argc : count of option
 * @param argv : array which contain all string option
 */
void option(int argc, char **argv);

#endif // !_option_h