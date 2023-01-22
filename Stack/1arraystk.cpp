#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int *arr;
    int size;
    int top;

public:
    Stack()
    {
        size = 10;
        arr = new int{size};
        top = -1;
    }

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    int stackFull();
    int stackEmpty();

    void push(int x);
    int pop();
    int peak(int pos);

    void display();
};

int Stack::stackFull()
{
    if (top >= size)
        return 1;
    else
        return 0;
}

int Stack::stackEmpty()
{
    if (top < 0)
        return 1;
    else
        return 0;
}

void Stack::push(int x)
{
    if (stackFull())
    {
        cout << "stack overflow";
    }
    else
    {
        top++;
        arr[top] = x;
    }
}

int Stack::pop()
{
    int x = -1;
    if (!stackEmpty())
    {
        x = arr[top];
        top--;
    }
    return x;
}

int Stack::peak(int pos)
{
    int x = -1;
    if (!stackEmpty() && (pos <= top + 1))
    {
        x = arr[top - pos + 1];
    }
    return x;
}

int main()
{
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout<<st.pop()<<endl;
    cout<<st.peak(2)<<endl;
    return 0;
}
