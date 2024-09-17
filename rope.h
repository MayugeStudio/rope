#ifndef ROPE_H_
#define ROPE_H_

#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>

#ifndef ROPE_DEF
#define ROPE_DEF
#endif // ROPE_DEF

typedef struct Rope_t{
    const char *data;
    size_t length;
} Rope;

ROPE_DEF Rope rope_from_parts(const char *data, size_t length);
ROPE_DEF Rope rope_from_cstr(const char *data);
ROPE_DEF Rope rope_trim_left(Rope rope);
ROPE_DEF Rope rope_trim_right(Rope rope);
ROPE_DEF Rope rope_trim(Rope rope);
ROPE_DEF Rope rope_chop_by_delim(Rope *rope, char delim);
ROPE_DEF bool rope_is_degit(Rope rope);

#endif // ROPE_H_
 
