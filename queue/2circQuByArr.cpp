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
        rear = 0;
        front = 0;
    }
    Queue(int s)
    {
        size = s;
        arr = new int[size];
        rear = 0;
        front = 0;
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
    if ((rear + 1) % size == front)
        return 1;
    else
        return 0;
}

void Queue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue is already full" << endl;
    }
    else
    {
        (rear)++;
        rear %= size;
        arr[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "Queue is already empty!" << endl;
        return -1;
    }
    else
    {
        front = (front + 1) % size;
        x = arr[front];
    }
    return x;
}

int main()
{

    Queue st(5);

    st.enqueue(10);
    st.enqueue(10);
    st.enqueue(10);
    cout << st.dequeue() << endl;

    
    st.enqueue(10);
    st.enqueue(10);

    cout << st.dequeue() << endl;
    cout << st.dequeue() << endl;
    cout << st.dequeue() << endl;
    cout << st.dequeue() << endl;
    cout << st.dequeue() << endl;

    return 0;
}