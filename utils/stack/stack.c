#include "stack.h"
#define _PRIVATE_

#define PUSH 0
#define POP 1
#define PRINT 2
#define FREE 3

//PRIVATE FUNCTIONS
void push(stack *s, int value)
{   
    node *n = (node*) malloc(sizeof(node));
    n->val = value;

    if (s->len == 0)
    {
        n->next_node = 0;
    }
    else
    {
        n->next_node = s->nodes[s->len-1];
    }

    s->nodes[s->len++] = n;
    printf("new size: %d\n", sizeof(node*) * s->len);
    s->nodes = (node**) realloc(s->nodes, sizeof(node*) * s->len);    

    if (!s->nodes)
    {
        printf("COULDNT ALLOCATE MEMORY FOR MORE NODES\n");
        return;
    }

    s->top_node = n;
    //printf("Adding node: %d next %p\n", s->nodes[s->len-1]->val, s->nodes[s->len-1]->next_node);
}

void pop()
{

}

void printStack(stack *s)
{
    node *head = s->top_node;
    for (int i = 0; i < s->len; i++)
    {
        printf("%d -> ", head->val);
        head = head->next_node;
    }
    printf("\n");
}

void freeStack(stack *s)
{
    free(s->nodes);
    free(s->self);
}

stack Stack()
{
    stack *s = (stack*) malloc(sizeof(stack));
    s->self = s;
    s->len = 0;

    s->nodes = (node**) realloc(NULL, sizeof(node*) * s->len);

    s->push = push;
    s->pop = pop;
    s->print = printStack;
    s->free = freeStack;

    return *s;
}