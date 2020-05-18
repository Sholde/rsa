#ifndef _generate_h
#define _generate_h

/**
 * Init key
 */
key *init_key(void);

/**
 * Clear key
 */
void clear_key(key *k);

/**
 * Generate a prime
 * @param p : prime
 * @param size : size of prime
 */
void next_prime(mpz_t p, int size);

/**
 * Euclide
 * @param u : u
 * @param v : v
 * @param phi_n : phi_n
 * @param e : e
 */
void euclide(mpz_t u, mpz_t v, mpz_t phi_n, mpz_t e);

/**
 * Compute e, the public exponent
 */
void compute_e(key *k, mpz_t phi_n);

/**
 * Compute d, the public exponent
 */
void compute_d(key *k, mpz_t phi_n);

/**
 * Generate a pair of key
 * @param size_modulus : size of the modulus
 * @return k : key
 */
key *generate(int size_modulus);

#endif // !_generate_h