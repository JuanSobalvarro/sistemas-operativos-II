#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct linkedlist 
{
    struct linkedlist *self;
    struct node *head;
    int len;

    void (*insertAt)(struct linkedlist*, int, int);
    void (*deleteAt)(struct linkedlist*, int);
    void (*print)(struct linkedlist*);

    void (*free)(struct linkedlist*);
} linkedlist;

linkedlist LinkedList();

#ifdef _PRIVATE_

node *createNode(int val);

void insertat(struct linkedlist *ll, int val, int pos);

void deleteat(struct linkedlist *ll, int pos);

void print(struct linkedlist *ll);

void freell(struct linkedlist *ll);

#endif



#endif