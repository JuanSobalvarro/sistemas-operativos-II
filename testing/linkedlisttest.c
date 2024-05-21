#include "../utils/linked-lists/linkedlist.h"

int main()
{
    linkedlist ll = LinkedList();

    ll.insertAt(ll.self, 2, 0);

    ll.print(ll.self);

    ll.deleteAt(ll.self, 0);

    ll.print(ll.self);

    ll.insertAt(ll.self, 3, 0);
    ll.insertAt(ll.self, 4, 0);

    ll.print(ll.self);

    ll.insertAt(ll.self, -1, 1);

    ll.print(ll.self);

    ll.deleteAt(ll.self, 2);

    ll.print(ll.self);

    ll.insertAt(ll.self, 8, 8);

    ll.print(ll.self);

    ll.deleteAt(ll.self, 8);

    ll.print(ll.self);

    ll.free(ll.self);

    return 0;
}