#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue
{
    int size;
    int front;
    int rear;
    T *arr;

public:
    Queue();
    Queue(int s);

    int isEmpty();
    int isFull();

    void enqueue(T n);
    T dequeue();
};

template <class T>
Queue<T>::Queue()
{
    size = 10;
    rear = -1;
    front = -1;
    arr = new T[size];
}

template <class T>
Queue<T>::Queue(int s)
{
    size = s;
    rear = -1;
    front = -1;
    arr = new T[size];
}

template <class T>
int Queue<T>::isEmpty()
{
    if (rear == front)
        return 1;
    return 0;
}
template <class T>
int Queue<T>::isFull()
{
    if (rear >= size)
        return 1;
    return 0;
}
template <class T>
void Queue<T>::enqueue(T n)
{
    if (isFull())
        cout << "Queue is full\n";
    else
    {
        rear++;
        arr[rear] = n;
    }
}
template <class T>
T Queue<T>::dequeue()
{
    T x = -1;
    if (isEmpty())
    {
        cout << "Queue is empty\n";
    }
    else
    {
        front++;
        x = arr[front];
    }

    if (rear == front)
        rear = front = -1;
    return x;
}
int main()
{
    Queue<int> t;
    t.enqueue(5);
    t.enqueue(85);
    t.enqueue(96);
    cout << t.dequeue() << endl;

        return 0;
}