#include <stdio.h>
#include "./rope.h"

int main(void)
{
    Rope rope = rope_from_cstr("   hello world   \n");
    printf("%.*s\n", (int) rope.length, rope.data);

    rope = rope_trim_left(rope);
    printf("%.*s\n", (int) rope.length, rope.data);
    rope = rope_trim_right(rope);
    printf("%.*s\n", (int) rope.length, rope.data);

    Rope world = rope_chop_by_delim(&rope, ' ');
    printf("%.*s\n", (int) rope.length, rope.data);
    printf("%.*s\n", (int) world.length, world.data);
}
