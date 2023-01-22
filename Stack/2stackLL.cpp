#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
    Node *top;

public:
    Stack() { top = NULL; }
    void push(int x);
    int pop();
    void peek();
};

void Stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "Stack is full!" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;
    if (top == NULL)
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        Node *p = top;
        x = top->data;
        top = top->next;
        delete p;
    }

    return x;
}

void Stack::peek()
{
    Node *p = top;
    if (p == NULL)
    {
        cout << "LL is empty!" << endl;
    }
    else
    {
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main()
{
    Stack s;
    s.push(10);
    s.push(18);
    s.push(15);

    s.push(12);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}