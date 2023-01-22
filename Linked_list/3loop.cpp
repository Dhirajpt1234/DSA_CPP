#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

bool isLoop(Node *head)
{
    Node *p = head, *q = head;
    do
    {
        p = p->next;
        q = q->next;
        if (q != NULL)
        {
            q = q->next;
        }
    } while (q && p && q != p);

    if (p == q)
    {
        return true;
    }
    return false;
}

int main()
{
    Node *first, *a, *b, *c, *d, *e, *f;

    first->data = 12;
    first->next = a;

    a->data = 34;
    a->next = b;

    b->data = 34;
    b->next = c;

    c->data = 34;
    c->next = d;

    d->data = 34;
    d->next = e;

    e->data = 34;
    e->next = f;

    f->data = 8979;
    f->next = NULL;

    if (isLoop(first))
    {
        cout << "This is not looped";
    }
    else
    {
        cout << "This is a loop";
    }
    return 0;
}