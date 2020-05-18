#ifndef _option_h
#define _option_h

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