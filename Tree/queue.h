#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;
};

class Queue
{
    int size;
    int front;
    int rear;
    Node **arr;

public:
    Queue()
    {
        size = 5;
        arr = new Node *[size];
        rear = -1;
        front = -1;
    }
    Queue(int s)
    {
        size = s;
        arr = new Node *[size];
        rear = -1;
        front = -1;
    }

    void enqueue(Node *x);
    Node *dequeue();
    int isFull();
    int isEmpty();
    int getfront();
    int getrear();
};

int Queue::isEmpty()
{
    if (rear == front)
        return 1;
    else
        return 0;
}

int Queue::isFull()
{
    if (rear == size - 1)
        return 1;
    else
        return 0;
}

void Queue::enqueue(Node *x)
{
    if (isFull())
    {
        cout << "Queue is already full";
    }
    else
    {
        rear++;
        arr[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x = NULL;
    if (isEmpty())
    {
        return x;
    }
    else
    {
        front++;
        x = arr[front];
    }

    if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    return x;
}
