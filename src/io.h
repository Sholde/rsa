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

/**
 * Write a string on file
 * @param path : path
 * @param s : string
 */
void write_file(char *path, char *s);

/**
 * Check option
 * @param path : path
 * @return string
 */
char *read_file(char *path);

#endif // !_io_h