#include <stdio.h>
#include "../utils/stack/stack.h"

int main()
{
    stack s = Stack();

    //printf("Address s: %p, self: %p\n", &s, s.self);

    s.push(&s, 10);
    s.print(&s);

    s.push(&s, 2);
    s.print(&s);

    s.push(&s, -2);
    s.push(&s, -7);

    s.print(&s);
    
    s.free(&s);
    return 0;
}