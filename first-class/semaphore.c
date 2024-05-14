#include <stdlib.h>
#include <stdio.h>

typedef struct sem 
{
    size_t *val;
} sem;

int semwait(sem *s);
int sempost(sem *s);
void seminit(sem *s, int pshared, unsigned int value);
void semdestroy(sem *s);

int main()
{

    return 0;
}