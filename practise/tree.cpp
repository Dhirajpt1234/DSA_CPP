#include <bits/stdc++.h>
#include "queue.h"
#include "stack.h"

using namespace std;

class Tree
{
    Node *root;

public:
    Tree() { root = NULL; }

    void createTree();
    void preOrder(Node *p);
    void preOrder()
    {
        preOrder(root);
        cout << endl;
    }
    void postOrder(Node *p);
    void postOrder()
    {
        postOrder(root);
        cout << endl;
    }
    void inOrder(Node *p);
    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }
    void ITlevel(Node *p);
    void ITlevel()
    {
        ITlevel(root);
    }
    void ITpre(Node *p);
    void ITpre()
    {
        ITpre(root);
        cout << endl;
    }

    void ITin(Node *p);
    void ITin()
    {
        ITin(root);
        cout << endl;
    }
    int height(Node *p);
    void height()
    {
        cout << height(root) << endl;
    }
    int count(Node *p);
    void count()
    {
        cout << count(root) << endl;
    }

    int sum(Node *p);
    void sum()
    {
        cout << sum(root) << endl;
    }
    int deg2Node(Node *p);
    void deg2Node()
    {
        cout << deg2Node(root) << endl;
    }
};

void Tree::createTree()
{
    Node *p, *r;
    r = new Node();
    int x = -1;
    cout << " Enter the data of the root : ";
    cin >> x;

    r->data = x;
    r->left = NULL;
    r->right = NULL;

    root = r;

    Queue q(100);
    q.enqueue(r);

    while (!(q.isEmpty()))
    {
        p = q.dequeue();
        cout << " This is the another level \n ";
        x = -1;
        cout << " The pointer is on node " << p->data << endl;

        // for left part
        cout << " Enter value of the left of the " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            Node *new_node = new Node();
            new_node->data = x;
            new_node->left = NULL;
            new_node->right = NULL;
            p->left = new_node;
            q.enqueue(new_node);
        }

        // for right part
        cout << " Enter value of the left of the " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            Node *new_node = new Node();
            new_node->data = x;
            new_node->left = NULL;
            new_node->right = NULL;
            p->right = new_node;
            q.enqueue(new_node);
        }
    }
}

void Tree::preOrder(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preOrder(p->left);
        preOrder(p->right);
    }
}

void Tree::inOrder(Node *p)
{
    if (p != NULL)
    {
        inOrder(p->left);
        cout << p->data << " ";
        inOrder(p->right);
    }
}

void Tree::postOrder(Node *p)
{
    if (p != NULL)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->data << " ";
    }
}

void Tree::ITpre(Node *p)
{

    Stack<Node *> st(50);
    while ((!st.isEmpty()) || (p != NULL))
    {
        if (p != NULL)
        {
            cout << p->data << " ";
            st.push(p);
            p = p->left;
        }
        else
        {
            p = st.pop();
            p = p->right;
        }
    }
}

void Tree::ITin(Node *p)
{
    Stack<Node *> st(50);
    while ((!st.isEmpty()) || p != NULL)
    {
        if (p != NULL)
        {
            st.push(p);
            p = p->left;
        }
        else
        {
            p = st.pop();
            cout << p->data << " ";
            p = p->right;
        }
    }
}

void Tree::ITlevel(Node *r)
{
    Queue q(100);
    Node *p = r;
    if (p != NULL)
        cout << p->data << ' ';
    q.enqueue(p->left);
    q.enqueue(p->right);

    while (p != NULL || !(q.isEmpty()))
    {
        p = q.dequeue();

        if (p != NULL)
        {
            cout << p->data << ' ';
            q.enqueue(p->left);
            q.enqueue(p->right);
        }
    }
}

int Tree::height(Node *p)
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

int Tree::count(Node *p)
{
    int l;
    int r;

    if (p != NULL)
    {
        l = height(p->left);
        r = height(p->right);
        return l + r + 1;
    }
    return 0;
}

int Tree::sum(Node *p)
{
    int x = 0;
    int y = 0;

    if (p != NULL)
    {
        x = sum(p->left);
        y = sum(p->right);
        return x + y + p->data;
    }
    return 0;
}
int Tree::deg2Node(Node *p)
{
    int l = 0;
    int r = 0;
    if (p != NULL)
    {
        l = deg2Node(p->left);
        r = deg2Node(p->right);
        if (p->left != NULL && p->right != NULL)
            return l + r + +1;
        else
            return l + r;
    }
    return 0;
}

int main()
{

    Tree t;
    t.createTree();
    t.preOrder();
    t.inOrder();
    t.postOrder();
    t.ITpre();
    t.ITin();
    t.ITlevel();
    t.height();
    t.count();
    t.sum();
    t.deg2Node();

    return 0;
}