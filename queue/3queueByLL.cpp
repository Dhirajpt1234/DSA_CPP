#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class List
{
    Node *front;
    Node *rear;

public:
    List() { rear = front = NULL; }

    int isFull();
    int isEmpty();

    void enqueue(int x);
    int dequeue();

    // ~List();
};

int List::isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

int List::isFull()
{
    Node *t = new Node();

    int x = 0;
    if (t == NULL)
        x = 1;
    else
        x = 0;

    delete t;
    return x;
}

void List::enqueue(int x)
{
    if (isFull())
    {
        cout << "List is full!" << endl;
    }
    else
    {
        Node *t = new Node();
        t->data = x;

        if (isEmpty())
        {
            rear = front = t;
            t->next = NULL;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int List::dequeue()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "LL is empty!";
    }
    else
    {
        x = front->data;
        Node *p = front;
        front = front->next;
        delete p;
    }
    return x;
}

int main()
{

    List ll;

    ll.enqueue(10);
    ll.enqueue(20);
    ll.enqueue(30);
    ll.enqueue(40);
    ll.enqueue(50);

    cout<<ll.dequeue()<<endl;
    cout<<ll.dequeue()<<endl;
    cout<<ll.dequeue()<<endl;
    return 0;
}