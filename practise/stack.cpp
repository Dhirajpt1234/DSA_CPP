#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack
{
    int size;
    T *arr;
    int top;

public:
    Stack();
    Stack(int s);

    int isEmpty();
    int isFull();

    void push(T n);
    T pop();
    T seek();
};

template <class T>
Stack<T>::Stack()
{
    size = 10;
    arr = new T[size];
    top = -1;
}
template <class T>
Stack<T>::Stack(int s)
{
    size = s;
    arr = new T[size];
    top = -1;
}
template <class T>
int Stack<T>::isEmpty()
{
    if (top < 1)
        return 1;
    else
        return 0;
}
template <class T>
int Stack<T>::isFull()
{
    if (top >= size)
    {
        return 1;
    }
    return 0;
}
template <class T>
void Stack<T>::push(T n)
{
    if (isFull())
    {
        cout << "\n Stack is full :  \n";
    }
    else
    {
        top++;
        arr[top] = n;
    }
}
template <class T>
T Stack<T>::pop()
{
    T x = -1;
    if (isEmpty())

    {
        cout << "Stack is Empty \n";
    }
    else
    {
        x = arr[top];
        top--;
    }
    return x;
}
template <class T>
T Stack<T>::seek()
{
    T x = -1;
    if (isEmpty())
    {
        cout << "Stack is Empty \n";
    }
    else
    {
        x = arr[top];
    }
    return x;
}

int main()
{

    Stack<int> s1(5);
    cout << s1.pop() << endl;

    s1.push(43);
    s1.push(53);
    s1.push(83);

    cout << s1.pop() << endl;
    cout << s1.seek() << endl;

    return 0;
}