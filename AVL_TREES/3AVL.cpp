// AVL tree
// Dhiraj Parmeshwar Thorat

#include <bits/stdc++.h>
using namespace std;
#define globalSpace 5;

class Node
{
    Node *left;
    Node *right;
    int data;

public:
    Node()
    {
        data = 0;
        left = right = NULL;
    }
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
    friend class AVL;
};

class AVL
{
    Node *root;

public:
    AVL()
    {
        root = NULL;
    }

    Node *insertRE(Node *p, int key);
    void insertRE(int key) { root = insertRE(root, key); }

    void insertIT(Node *p, int key);
    void insertIT(int key) { insertIT(root, key); }

    int getHeight(Node *p);
    int getHeight() { return getHeight(root); }

    int getBF(Node *p);

    void search(Node *p, int key);
    void search(int key) { search(root, key); }

    // traversals
    void preOrder(Node *p);
    void preOrder() { preOrder(root); }

    void inOrder(Node *p);
    void inOrder() { inOrder(root); }

    void postOrder(Node *p);
    void postOrder() { postOrder(root); }

    void print2D(Node *p, int space);
    void print2D(int space) { print2D(root, space); }

    Node *rigthRotate(Node *p);
    Node *leftRotate(Node *p);
};

Node *AVL::insertRE(Node *p, int key)
{
    if (p == NULL)
    {
        cout << "\nroot NULL hai";
        p = new Node(key);
        return p;
    }
    else if (key < p->data)
    {
        cout << "\n key < p.data condn";
        p->left = insertRE(p->left, key);
    }
    else if (key > p->data)
    {
        cout << "\nkey > p.data condn";
        p->right = insertRE(p->right, key);
    }
    else
    {

        cout << "\nDuplicate entry denied !";
        return p;
    }

    int n = getBF(p);
    cout << "\nGot bf : " << n << endl;

    if (n > 1 && key < p->left->data)
    {
        cout << "\n 1 condn : ";
        return rigthRotate(p);
    }
    else if (n > 1 && key > p->left->data)
    {
        cout << "\n 2 condn : ";
        p->left = leftRotate(p->left);
        return rigthRotate(p);
    }
    else if (n < -1 && key > p->right->data)
    {
        cout << "\n 3 condn : ";
        return leftRotate(p);
    }
    else if (n < -1 && key < p->right->data)
    {
        cout << "\n 4 condn : ";
        p->right = rigthRotate(p->right);
        return leftRotate(p);
    }
    cout << "\nSuccessfull added : " << key << endl;
    return p;
}

Node *AVL::leftRotate(Node *p)
{
    Node *x = p->right;
    Node *y = x->left;

    // rotation
    x->left = p;
    p->right = y;
    return x;
}

Node *AVL::rigthRotate(Node *p)
{

    Node *x = p->left;
    Node *y = x->right;

    // rotation

    x->right = p;
    p->left = y;

    return x;
}

int AVL::getBF(Node *p)
{
    if (p)
    {
        return (getHeight(p->left) - getHeight(p->right));
    }
    return 0;
}

int AVL::getHeight(Node *p)
{
    if (p)
    {
        int l = getHeight(p->left);
        int r = getHeight(p->right);
        return max(l + 1, r + 1);
    }
    return 0;
}

void AVL::search(Node *p, int key)
{
    if (p == NULL)
        cout << "\nElement is not Found";
    else if (p->data > key)
        search(p->left, key);
    else if (p->data < key)
        search(p->right, key);
    else
        cout << "\nCongo ! , element is found.";
}

void AVL::preOrder(Node *p)
{
    if (p)
    {
        cout << p->data << ' ';
        preOrder(p->left);
        preOrder(p->right);
    }
    return;
}

void AVL::inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->left);
        cout << p->data << ' ';
        inOrder(p->right);
    }
    return;
}

void AVL::postOrder(Node *p)
{
    if (p)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->data << " ";
    }
}

void AVL::print2D(Node *p, int space)
{
    if (p)
    {
        space += globalSpace;
        print2D(p->right, space);
        cout << "\n";
        int i = globalSpace;
        for (; i < space; i++)
            cout << " ";
        cout << p->data << '\n';
        print2D(p->left, space);
    }
    return;
}

int main()
{
    AVL a;
    int repeat = 1;
    do
    {
        cout << "\nEnter the choice : \n1.insert(iterative ) \n2.insert(Recursive) \n3.Preorder \n4.PostOrder \n5.Inorder \n.6.Print2D \n7.Get Height \n8.Exit \nYou chose : ";
        int choice;
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "\nINSERT(Iterative)";
            cout << "\nEnter the data : ";
            int data;
            // cin >> data;
            // a.insertIT(data);
            // break;
        case 2:
            cout << "\nINSERT(RE)";
            cout << "\nEnter the data : ";
            cin >> data;
            a.insertRE(data);
            break;
        case 3:
            cout << "\nPREORDER";
            a.preOrder();
            break;
        case 4:
            cout << "\nPOSTORDER";
            a.postOrder();
            break;
        case 5:
            cout << "\nINORDER";
            a.inOrder();
            break;
        case 6:
            cout << "\nPrint2D";
            a.print2D(5);
            break;
        case 7:
            cout << "\nHEIGHT";
            a.getHeight();
            break;
        case 8:
            repeat = 0;

        default:
            break;
        }
    } while (repeat);

    return 0;
}