#include "vt100.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int main()
{

    VT_WB w = {0};

    vtwb_append(&w, "Some String!", 12);
    assert(memcmp(w.buf, "Some String!", 12) == 0 && "Strings are the same");
    assert(w.len == 12);
    vtwb_append(&w, "1", 1);
    assert(*(w.buf + 12) == '1');

    vtwb_appendfmt(&w, "test %d", 1234);
    assert(memcmp(w.buf + 13, "test 1234", 8) == 0 && "fmt append");

    printf("buff is %d long\n", w.len);
    assert(w.len == 12 + 1 + 9 && "fmt append length");

    printf("all tests passed!\n");
    return 0;
}