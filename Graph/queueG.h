#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int size;
    int front;
    int rear;
    int *arr;

public:
    Queue()
    {
        size = 5;
        arr = new int[size];
        rear = -1;
        front = -1;
    }
    Queue(int s)
    {
        size = s;
        arr = new int[size];
        rear = -1;
        front = -1;
    }

    void enqueue(int x);
    int dequeue();
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

void Queue::enqueue(int x)
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

int Queue::dequeue()
{
    int x = -1;
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
