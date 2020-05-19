#include <stdio.h>
#include <stdlib.h>

#include "structure.h"
#include "option.h"
#include "io.h"

int main(int argc, char **argv) {
    //option(argc, argv);
    write_file("test.txt", "salut\n");
    char *s = read_file("test.txt");
    printf("s : %s", s);
    free(s);
    return 0;
}