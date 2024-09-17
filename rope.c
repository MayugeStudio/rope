#include "./rope.h"
#include <string.h>

ROPE_DEF Rope rope_from_parts(const char *data, size_t length)
{
    return (Rope) { .data=data, .length=length };
}

ROPE_DEF Rope rope_from_cstr(const char *cstr)
{
    return (Rope) { .data=cstr, .length=strlen(cstr) };
}

ROPE_DEF Rope rope_trim_left(Rope rope)
{
    int n = 0;
    while (isspace(rope.data[n]) && n < rope.length) {
        n++;
    }

    return (Rope) { .data=rope.data+n, .length=rope.length-n };
}

ROPE_DEF Rope rope_trim_right(Rope rope)
{
    int n = 0;
    while (isspace(rope.data[(rope.length-1)-n]) && n < rope.length) {
        n++;
    }

    return (Rope) { .data=rope.data, .length=rope.length-n };
}

ROPE_DEF Rope rope_trim(Rope rope)
{
    return rope_trim_left(rope_trim_right(rope));
}

ROPE_DEF Rope rope_chop_by_delim(Rope *rope, char delim)
{
    int n = 0;
    while (rope->data[n] != delim && n < rope->length) {
        n++;
    }
    return (Rope) { .data=rope->data+(n+1), .length=n };
}

