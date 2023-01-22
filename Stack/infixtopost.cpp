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
    char pop();
    void peek();
    int isfull();
    char peak();
    int isempty();
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

char Stack::pop()
{
    int x = 0;
    if (top == NULL)
    {
        return 0;
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

int precedence(char o)
{
    switch (o)
    {
    case '^':
        return 3;
        break;
    case '%':
    case '/':
    case '*':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;

    default:
        return -1;
        break;
    }
}

char Stack::peak()
{
    if (top != NULL)
    {
        return top->data;
    }
    else
    {
        return '\0';
    }
}

char *infixtopost(char *infix)
{
    Stack st;
    int index = 0;
    int pos = 0;
    char *post;
    char symbol;

    while (infix[index] != '\0')
    {
        symbol = infix[index];

        switch (symbol)
        {
        case '(':
            st.push(infix[index]);
            break;

        case ')':
            char temp = st.pop();
            while (temp != '(')
            {
                post[pos] = temp;
                pos++;
                temp = st.pop();
            }
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            while ((st.peak()) >= symbol)
            {
                char temp = st.pop();
                post[pos] = temp;
                pos++;
            }
            st.push(symbol);

        default:
            post[pos] = symbol;
            pos++;
            break;
        }

        index++;
    }
}

int main()
{
    char *p;
    cout << "Enter the string expression : ";
    cin >> p;

    cout << "Infix expression is : " << *p;

    return 0;
}