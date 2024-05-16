#include "stack.h"
#define _PRIVATE_

#define PUSH 0
#define POP 1
#define PRINT 2
#define FREE 3

//PRIVATE FUNCTIONS
node *createNode(int val)
{
    node *n = (node*) malloc(sizeof(node));
    n->val = val;
    n->next_node = NULL;

    return n;
}

void push(stack *s, int value)
{   
    node *n = createNode(value);
    n->next_node = s->top_node;

    s->top_node = n;

    if (!s->top_node)
    {
        printf("COULDNT ALLOCATE MEMORY FOR MORE NODES\n");
        return;
    }
    s->len++;
    //printf("Adding node: %d next %p\n", s->nodes[s->len-1]->val, s->nodes[s->len-1]->next_node);
}

void pop(stack *s)
{
    node *uwu = s->top_node;
    s->top_node = s->top_node->next_node;

    s->len--;
    free(uwu);
}

void printStack(stack *s)
{
    node *head = s->top_node;
    while (head != NULL)
    {
        printf("%d -> ", head->val);
        head = head->next_node;
    }
    printf("\n");
}

void freeStack(stack *s)
{
    // free nodes
    while (s->top_node != NULL)
    {
        pop(s);
    }

    // free structure
    free(s->self);
}

stack Stack()
{
    stack *s = (stack*) malloc(sizeof(stack));
    s->self = s;
    s->len = 0;

    s->top_node = NULL;

    s->push = push;
    s->pop = pop;
    s->print = printStack;
    s->free = freeStack;

    return *s;
}