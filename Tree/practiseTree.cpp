#include <bits/stdc++.h>
#include "queue.h"
using namespace std;

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