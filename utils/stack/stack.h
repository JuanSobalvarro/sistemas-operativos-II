#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node 
{
    int val;
    struct node *next_node;
} node;

/*
 * Top node will always be the one at the s->len-1
*/
typedef struct stack 
{
    struct stack *self;
    struct node *top_node;
    int len;
    
    // FUNCTIONS
    void (*push)(struct stack*, int);
    void (*pop)(struct stack*);
    void (*print)(struct stack*);
    
    void (*free)(struct stack*);
} stack;

stack Stack();

#ifdef _PRIVATE_

node createNode(int val);

void push(stack *s, int value);
void pop(stack *s);

void printStack(stack *s);

void freeStack(stack *s);

#endif

#endif