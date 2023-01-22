#include <bits/stdc++.h>
using namespace std;

class Node
{
    Node *left;
    Node *right;
    int height;
    int data;

    Node()
    {
        data = 0;
        left = right = NULL;
    }
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
    friend class AVL;
};

class AVL
{
    Node *root;

public:
    AVL() { root = NULL; } // constructor

    Node *insert(Node *p, int key); // create tree
    void insert(int key)
    {
        root = insert(root, key);
    }
    // facillators
    bool search(int k);
    int height(Node *p);

    // traversals
    void inorder(Node *p);
    void inorder()
    {
        inorder(root);
    }
    void preorder(Node *p);
    void preorder()
    {
        preorder(root);
    }
    void postorder(Node *p);
    void postorder()
    {
        postorder(root);
    }
};


Node * AVL::insert(Node * p ,int key)
{
   
}

















int AVL::height(Node *p)
{
    int l = 0;
    int r = 0;

    if (p != NULL)
    {
        l = height(p->left);
        r = height(p->right);
        return max(l + 1, r + 1);
    }
    return 0;
}

void AVL::inorder(Node *p)
{
    if (p)
    {
        inorder(p->left);
        cout << p->data << ' ';
        inorder(p->right);
    }
    return;
}

bool AVL::search(int key)
{
    Node *p = root;
    while (p != NULL)
    {
        if (p->data == key)
            return true;
        else if (key < p->data)
            p = p->left;
        else
            p = p->right;
    }
    return false;
}
int main()
{
    AVL a;
    a.insert(10);
    a.insert(25);
    a.insert(36);
    a.inorder();
    return 0;
}