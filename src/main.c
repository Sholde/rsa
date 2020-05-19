#include <stdio.h>
#include <stdlib.h>

#include "structure.h"
#include "option.h"
#include "io.h"
#include "convert.h"
#include "display.h"

int main(int argc, char **argv) {
    //option(argc, argv);
    write_file("test.txt", "salut\n");
    char *s = read_file("test.txt");
    printf("s : %s", s);
    msg *m = char_to_msg(s);
    char *t = msg_to_char(m);
    printf("t : %s", t);
    free(s);
    free(t);
    clear_msg(m);
    return 0;
}