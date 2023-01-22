// bst code for practise
// Dhiraj Parmeshwar Thorat

#include <bits/stdc++.h>
using namespace std;
#define Glolalspace 5;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node()
    {
        data = 0;
        left = right = NULL;
    }
    Node(int d)
    {
        left = right = NULL;
        data = d;
    }
    friend class bst;
};

class bst
{
    Node *root;

public:
    bst()
    {
        root = NULL;
    }
    Node *insert(Node *p, int key);
    void insert(int key)
    {
        root = insert(root, key);
    }
    void insertIT(Node *p, int key);
    void insertIT(int key)
    {
        insertIT(root, key);
    }
    int getHeight(Node *p);
    void getHeight()
    {
        cout << "height of the tree is : ";
        cout << getHeight(root);
    }
    void preorder(Node *p);
    void preorder()
    {
        cout << "\nData is as follows : ";
        preorder(root);
    }
    void print2D(Node *p, int space);
    void print2D(int space)
    {
        print2D(root, space);
    }
    bool Search(Node *p, int key);
    void search(int key)
    {
        if (Search(root, key))
            cout << "\nElement is present.👌👌";
        else
            cout << "\nElement is absent";
    }
};

Node *bst::insert(Node *p, int key)
{
    if (p == NULL)
    {
        Node *t = new Node(key);
        return t;
    }
    else if (p->data > key)
    {
        p->left = insert(p->left, key);
    }
    else if (p->data < key)
    {
        p->right = insert(p->right, key);
    }
    else
    {
        cout << "\nDuplicate value is not allowed ";
    }
    return p;
}

void bst::insertIT(Node *p, int key)
{
    Node *new_node = new Node(key);
    if (p == NULL)
    {
        root = new_node;
        return;
    }
    Node *r;
    while (p != NULL)
    {
        r = p;
        if (p->data == key)
        {
            cout << "\nDuplicate Not Allowed : ";
            return;
        }
        else if (key < p->data)
            p = p->left;
        else
            p = p->right;
    }

    if (r->data > new_node->data)
        r->left = new_node;
    else
        r->right = new_node;
    return;
}

void bst::preorder(Node *p)
{
    if (p)
    {
        cout << p->data << ' ';
        preorder(p->left);
        preorder(p->right);
    }
}

int bst::getHeight(Node *p)
{
    if (p != NULL)
    {
        int l = getHeight(p->left);
        int r = getHeight(p->right);

        return max(l + 1, r + 1);
    }
    else
        return 0;
}

bool bst::Search(Node *p, int key)
{
    if (p == NULL)
        return false;
    if (key < p->data)
        Search(p->left, key);
    else if (key > p->data)
        Search(p->right, key);
    else if (key == p->data)
        return true;
}

void bst::print2D(Node *p, int space)
{
    if (p)
    {
        space += Glolalspace;
        print2D(p->right, space);
        cout << "\n";
        int i = Glolalspace;
        for (; i < space; i++)
            cout << " ";
        cout << p->data << '\n';
        print2D(p->left, space);
    }
    return;
}

int main()
{

    bst t1;

    int choice = 1;
    do
    {
        cout << "\nThe options are as follows : \n1.insert \n2.display \n3.Exit \n4.Height \n5.Search \n6.Insert iterative \n7.Print2D ";
        cout << "\nYour Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "\nINSERT";
            cout << "\nEnter the data : ";
            cin >> data;
            t1.insert(data);
            break;

        case 2:
            cout << " \nDISPLAY";
            t1.preorder();
            break;

        case 3:
            cout << "\nEXIT";
            choice = 0;
            break;

        case 4:
            t1.getHeight();

        case 5:
            cout << "\nSEARCH";
            int key;
            cout << "\nEnter the key : ";
            cin >> key;
            t1.search(key);

        case 6:
            cout << "\nINSERT";
            cout << "\nEnter the data : ";
            cin >> data;
            t1.insertIT(data);
        case 7:
            t1.print2D(5);

        default:
            break;
        }
    } while (choice);

    return 0;
}