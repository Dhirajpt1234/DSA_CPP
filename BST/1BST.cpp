#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;
    Node()
    {
        left = NULL;
        right = NULL;
    }
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Tree
{
    Node *root;

public:
    Tree() { root = NULL; }
    void insertIT(int x);
    Node *insertRE(Node *p, int x);
    void insertRE(int x)
    {
        root = insertRE(root, x);
    }
    int searchIT(int x);
    int searchRE(Node *p, int x);
    int searchRE(int x) { return searchRE(root, x); }
    void inorder(Node *p);
    void inorder()
    {
        inorder(root);
    }
};

Node *Tree::insertRE(Node *node, int key)
{

    if (node == NULL)
    {
        Node *t = new Node(key);
        return t;
    }

    if (key == node->data)
    {
        cout << "No duplicates allowed ";
        return node;
    }
    else if (key < node->data)
    {
        node->left = insertRE(node->left, key);
    }
    else if (key > node->data)
    {
         node->right = insertRE(node->right, key);
    }
    return node;
}

void Tree::insertIT(int x)
{

    Node *r = NULL;
    Node *t = root;
    if (root == NULL)
    {
        Node *s = new Node();
        s->data = x;
        s->left = s->right = NULL;
        root = s;
        return;
    }
    else
    {
        while (t != NULL)
        {
            r = t;
            if (t->data == x)
            {
                return;
            }
            else if (t->data < x)
            {
                t = t->right;
            }
            else
            {
                t = t->left;
            }
        }

        t = new Node();
        t->data = x;
        t->left = t->right = NULL;
        if (x < r->data)
        {
            r->left = t;
        }
        else
        {
            r->right = t;
        }
        return;
    }
}

int Tree::searchIT(int x)
{
    Node *p = root;
    while (p != NULL)
    {
        cout << " iterative : " << p->data << endl;
        if (p->data == x)
        {
            return 1;
        }
        else if (x < p->data)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return 0;
}

int Tree::searchRE(Node *p, int x)
{
    if (p == NULL)
    {
        return 0;
    }
    else if (p->data == x)
    {
        return 1;
    }
    else if (x < p->data)
    {
        return searchRE(p->left, x);
    }
    else
        return searchRE(p->right, x);
}

void Tree::inorder(Node *p)
{
    if (p)
    {
        inorder(p->left);
        cout << p->data << ' ';
        inorder(p->right);
    }
}
int main()
{
    Tree t;
    t.insertIT(500);
    t.insertIT(200);
    t.insertIT(600);
    t.insertIT(400);

    t.insertRE(4);
    t.insertRE(10);
    t.insertRE(12);
    t.inorder();

    if (t.searchRE(400))
        cout
            << "Found";
    else
        cout << "Not Found";

    return 0;
}