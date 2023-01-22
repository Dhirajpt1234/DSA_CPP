#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

class Stack
{
public:
    Node *top;

    Stack() { top = NULL; }
    void push(char x);
    int pop();
    void peek();
};

void Stack::push(char x)
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

int isbalanced(char *s)
{
    Stack st;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.top == NULL)
            {
                return 0;
            }
            else
            {
                st.pop();
            }
        }
    }
    if (st.top != NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    char *p;
    cout << "Enter the string expression : ";
    cin >> p;

    if (isbalanced(p))
    {
        cout << "It is balanced!";
    }
    else
        cout << "Not balanced !";

    return 0;
}