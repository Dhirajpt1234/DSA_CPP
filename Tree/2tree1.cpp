#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;

// public:
};

class Queue
{
    int rear;
    int front;
    int size;
    Node **arr;

public:
    Queue()
    {
        rear = -1;
        front = -1;
        size = 100;
        arr = new Node *[size];
    }
    Queue(int s)
    {
        rear = -1;
        front = -1;
        size = s;
        arr = new Node *[size];
    }

    void enqueue(Node *);
    Node *dequeue();
    int isEmpty();
    int isFull();
};

int Queue::isEmpty()
{
    if (rear == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Queue::isFull()
{
    if (rear == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Queue::enqueue(Node *p)
{
    if (isFull())
    {
        cout << "Queue is full : ";
    }
    else
    {
        rear++;
        arr[rear] = p;
    }
}

Node *Queue::dequeue()
{
    Node *x = NULL;
    if (isEmpty())
    {
        cout << "queue is empty  : ";
    }
    else
    {
        front++;
        x = arr[front];
    }
    return x;
}

// Queue is completed!
//////////////////////
// Stack is started !

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
// Treee is started !

class Tree
{
    Node *root;

public:
    Tree()
    {
        cout << "Tree is created ! \n";
        root = NULL;
    }

    void createTree();
    void preorder(Node *p);
    void preorder() { preorder(root); } // dummy fun to call pre with root

    void postOrder(Node *p);
    void postOrder() { postOrder(root); } // dummy fun to call pre with root

    void inOrder(Node *p);
    void inOrder() { inOrder(root); } // dummy fun to call pre with root

    void ITpreOrder();
    void ITinOrder();
    // void ITpostOrder();
    void levelOrder();

    int height(Node *p);
    void height() { cout << height(root); }

    int count(Node *p);
    void count()
    {
        cout << count(root);
    }

    int countTwoDegreeNodes(Node *p);
    void countTwoDegreeNodes()
    {
        cout << countTwoDegreeNodes(root);
    }

    int countSum(Node *p);
    void countSum()
    {
        cout << countSum(root);
    }
};

void Tree::createTree()
{
    Queue q(100);
    root = new Node();
    Node *p = NULL;

    cout << "Enter the value of the root : ";
    cin >> root->data;
    root->left = root->right = NULL;

    q.enqueue(root);

    while (!q.isEmpty())
    {
        int x = -1;
        p = q.dequeue();

        // code for left node
        cout << "Enter the data for node left to the " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            Node *t = new Node();
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            q.enqueue(t);
        }

        // code for right node
        cout << "Enter the data for node right to the " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            Node *t = new Node();
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            q.enqueue(t);
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

void Tree::postOrder(Node *p)
{
    if (p)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->data << " ";
    }
}

void Tree::inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->left);
        cout << p->data << " ";
        inOrder(p->right);
    }
}

void Tree::ITpreOrder()
{
    Node *p = root;
    Stack st(50);

    while (!st.isEmpty() || (p != NULL))
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

void Tree::ITinOrder()
{
    Node *p = root;
    Stack st(50);

    while ((p != NULL) || !st.isEmpty())
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

// void Tree::ITpostOrder()
// {
//     Node * p = root ;
//     Stack st(50);

//     while(p != NULL || (!st.isEmpty()))
//     {
//        if(p!= NULL)
//        {
//             st.push(p);
//         p  = p->left;
//        }
//        else
//        {
//            Node * temp = st.pop();

//            if(temp>0)
//            {
//                st.push(-(temp));

//            }
//        }
//     }

// }

void Tree::levelOrder()
{
    Node *p = root;
    Queue q(50);

    if (root != NULL)
        cout << root->data << " ";
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();

        if (p->left)
        {
            cout << p->left->data << ' ';
            q.enqueue(p->left);
        }
        if (p->right)
        {
            cout << p->right->data << " ";
            q.enqueue(p->right);
        }
    }
}

int Tree::count(Node *p)
{

    int x, y;
    x = y = 0;

    if (p != NULL)
    {
        x = count(p->left);
        y = count(p->right);
        return x + y + 1;
    }
    else
    {
        return 0;
    }
}

int Tree::countTwoDegreeNodes(Node *p)
{
    int x, y;
    x = y = 0;

    if (p != NULL)
    {
        x = countTwoDegreeNodes(p->left);
        y = countTwoDegreeNodes(p->right);
        if ((p->right != NULL) && (p->left != NULL))
        {
            return x + y + 1;
        }
        else
            return x + y;
    }
    return 0;
}

int Tree::countSum(Node *p)
{

    int x, y;
    x = y = 0;

    if (p != NULL)
    {
        x = countSum(p->left);
        y = countSum(p->right);
        return x + y + p->data;
    }
    else
    {
        return 0;
    }
}

int Tree::height(Node *p)
{

    int x, y;
    x = y = 0;

    if (p != NULL)
    {
        x = height(p->left);
        y = height(p->right);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    Tree t;
    t.createTree();
    cout << "\nPreorder traversal is as follows : ";
    t.preorder();

    cout << "\nPreorder traversal using iteration is : ";
    t.ITpreOrder();

    cout << "\ninorder traversal is as follows : ";
    t.inOrder();

    cout << "\ninorder traversal using iteration is : ";
    t.ITinOrder();

    cout << "\npostorder traversal is as follows : ";
    t.postOrder();

    cout << "\npostorder traversal using iteration is : ";
    // t.ITpostOrder();

    cout << "\npostorder traversal using iteration is : ";
    t.levelOrder();

    cout << "\nCount of the nodes is : ";
    t.count();

    cout << "\nCount of the 2 degree nodes is : ";
    t.countTwoDegreeNodes();

    cout << "\nCount of sum of the all nodes is : ";
    t.countSum();

    cout << "\nThe heigth of the tree is : ";
    t.height();

    cout << "\ncongratulation Dhiraj!";

    return 0;
}

////congratulation Dhiraj!
