#ifndef _io_h
#define _io_h

/**
 * Print a bold string on stdout
 * @param k : key
 */
void write_key(key *k);

/**
 * Check option
 * @return k : key
 */
key *read_key(void);

#endif // !_io_h