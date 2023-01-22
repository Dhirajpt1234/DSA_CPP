#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    int data;
    Node *right;
};

class Tree
{
    Node *root;

public:
    Tree() { root = NULL; }
    void insertIT(int x);
};

void Tree::insertIT(int x)
{
    Node *r, *t;
    r = NULL;
    t = root;
    Node *p = new Node();
    p->data = x;
    p->left = p->right = NULL;

    if (root == NULL)
    {
        root = p;
        return;
    }
    else
    {
        while (t != NULL)
        {
            r = t;
            if (x < t->data)
            {
                t = t->left;
            }
            else if (x > t->data)
            {
                t = t->right;
            }
            else
            {
                cout << "element is already present!";
                return;
            }
        }

        if (x < r->data)
            r->left = p;
        else
            r->right = p;
        return;
    }
}

int main()
{

    return 0;
}