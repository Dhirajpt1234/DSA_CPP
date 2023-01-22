#include <bits/stdc++.h>
#include "queue.h"
using namespace std;

class Stack
{
    int size;
    int top;
    Node **arr;

public:
    Stack()
    {
        size = 100;
        top = -1;
        arr = new Node *[size];
    }
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new Node *[size];
    }

    void push(Node *p);
    Node *pop();
    int isFull();
    int isEmpty();
};

int Stack::isFull()
{
    if (top == size - 1)
        return 1;
    else
        return 0;
}

int Stack::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void Stack::push(Node *p)
{
    if (isFull())
    {
        cout << "Stack is full";
    }
    else
    {
        top++;
        arr[top] = p;
    }
}

Node *Stack::pop()
{
    Node *x = NULL;
    if (isEmpty())
        cout << "Stack is empty! ";
    else
    {
        x = arr[top];
        top--;
    }
    return x;
}

class Tree
{
    Node *root;

public:
    Tree() { root = NULL; }

    void Treectreate();
    void preorder() { preorder(root); };
    void preorder(Node *p);
    void postorder(Node *p);
    void inorder(Node *p);
    void levelorder(Node *p);
    int height(Node *p);

    void preorderIT(Node * p)
    {
        
    }
};

void Tree::Treectreate()
{

    Queue q(100);
    Node *p, *r;
    int x = -1;
    r = new Node();
    cout << "Enter the value Root : ";
    cin >> r->data;
    r->right = r->left = NULL;
    root = r;

    q.enqueue(root);

    while (!q.isEmpty())
    {
        cout << "\n It is another level!\n";
        cout << "\nroot is at " << root->data << endl;
        p = q.dequeue();

        // for left side of node
        cout << "Enter the data of left of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            Node *t = new Node();
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            q.enqueue(t);
            cout << "the new left is created t" << t->data << endl
                 << t->left << endl
                 << t->right << endl;
        }

        // for right side of the node
        cout << "Enter the data of right of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {

            Node *t = new Node();
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            p->right = t;
            q.enqueue(t);
            cout << "the new right is created t" << t->data << endl
                 << t->left << endl
                 << t->right << endl;
        }
    }
}

void Tree::preorder(Node *p)
{
    if (p)
    {

        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}


//
int main()
{
    Tree t;
    t.Treectreate();
    t.preorder();
}