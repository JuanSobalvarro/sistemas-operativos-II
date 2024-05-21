#include "linkedlist.h"

// PRIVATE FUNCTIONS

node *createNode(int val)
{
    node *n = malloc(sizeof(node));

    if (!n)
    {
        printf("Couldnt Allocate memory for new node\n");
        return NULL;
    }
    n->data = val;
    n->next = NULL;

    return n;
}

void insertat(struct linkedlist *ll, int val, int pos)
{
    if (pos < 0)
    {
        printf("Position not valid\n");
        return;
    }
    else if (pos > ll->len)
    {
        printf("Position not valid inserting at the end\n");
        pos = ll->len;
    }
    else if (pos == 0)
    {
        node *head = ll->head;
        ll->head = createNode(val);
        ll->head->next = head;

        ll->len++;
        return;
    }
    
    
    node *temp = ll->head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    
    node *next = temp->next;
    temp->next = createNode(val);
    temp->next->next = next;
    ll->len++;
}

void deleteat(struct linkedlist *ll, int pos)
{
    if (pos < 0)
    {
        printf("Position not valid\n");
        return;
    }
    else if (pos > ll->len)
    {
        printf("Position not valid deleting at the end\n");
        pos = ll->len - 1;
    }
    else if (pos == 0 && ll->head != NULL)
    {
        node *tmp = ll->head->next;

        free(ll->head);
        ll->head = tmp;

        ll->len--;
        return;
    }

    node *temp = ll->head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    node *next = temp->next;
    temp->next = next->next;
    free(next);
    ll->len--;
}

void print(struct linkedlist *ll)
{
    node *temp = ll->head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}   

void freell(struct linkedlist *ll)
{
    while (ll->head->next != NULL)
    {
        node *temp = ll->head;
        ll->head = ll->head->next;
        free(temp);
    }
    free(ll->head);
    free(ll->self);
}

linkedlist LinkedList()
{
    linkedlist *ll = malloc(sizeof(linkedlist));
    
    ll->self = ll;

    ll->head = NULL;
    ll->len = 0;

    ll->insertAt = insertat;
    ll->deleteAt = deleteat;
    ll->print = print;
    ll->free = freell;

    return *ll;
}