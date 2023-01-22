#include <bits/stdc++.h>
using namespace std;

class maxHeap
{
public:
    int *arr;
    int size;
    int capacity;

    maxHeap(int c)
    {
        capacity = c;
        size = 0;
        arr = new int[capacity];
    }
    maxHeap()
    {
        capacity = 10;
        size = 0;
        arr = new int[capacity];
    }

    void insert(int d);
    void extract();
    void printArray();
    int left(int d);
    int right(int d);
    int parent(int d);
    int maxElement() { return arr[0]; }
};

void maxHeap::insert(int d)
{
    if (size >= (capacity - 1))
        cout << "\nStack is already full!";
    else
    {
        size++;
        arr[size - 1] = d;

        while (arr[size - 1] > arr[size / 2 - 1])
        {
            swap(arr[size - 1], arr[size / 2 - 1]);
            size /= 2;
        }
    }
}

void maxHeap::printArray()
{
    cout << "\nThe heap  array is as follow : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
}

void maxHeap::extract()
{
    int i = 1, j;
    int temp = arr[0];
    j = arr[2 * i - 1] > arr[(2 * i)] ? (2 * i - 1) : (2 * i);

    while (arr[i] < arr[j])
    {
        if (j < size && arr[i] < arr[j])
        {
            swap(arr[i], arr[j]);
            i = j;
            j = arr[2 * i - 1] > arr[(2 * i)] ? (2 * i - 1) : (2 * i);
        }
        else
            break;
    }

    size--;
}

int maxHeap::left(int d)
{
    int pos = -1;
    for (int i = 0; i < size; i++)
    {
        if (i == d)
            pos = i;
    }
    if (pos == -1)
    {
        cout << "\nElement is not present :  ";
        return -1;
    }
    int l = (2 * (pos + 1));
    if (l <= size)
        return arr[l];
    else
    {
        cout << "\nLeft chile is not present !";
        return -1;
    }
}

int maxHeap::right(int d)
{
    int pos = -1;
    for (int i = 0; i < size; i++)
    {
        if (i == d)
            pos = i;
    }
    if (pos == -1)
    {
        cout << "\nElement is not present :  ";
        return -1;
    }
    int l = (2 * (pos + 1) + 1);
    if (l <= size)
        return arr[l];
    else
    {
        cout << "\nRIght child is not present !";
        return -1;
    }
}

int maxHeap::parent(int d)
{
    int pos = -1;
    for (int i = 0; i < size; i++)
    {
        if (i == d)
            pos = i;
    }
    if (pos == -1)
    {
        cout << "\nElement is not present :  ";
        return -1;
    }
    else if (pos == 0)
    {
        cout << "\nSelected node is root node ";
        return arr[0];
    }
    int l = ((pos + 1) / 2 - 1);
    return arr[l];
}

int main()
{
    maxHeap h(10);
    int repeat = 1;
    do
    {
        cout << "\nEnter the choice : \n1.insert data \n2.heapify(insert) \n3.delete element \n4.print array \n5.left child \6.right child \n7.parent \n8.maximum element \n9.sorted array \n  \nYou chose : ";
        int choice;
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "\nINSERT";
            int data = 0;
            cout << "\nEnter the data : ";
            cin >> data;
            h.insert(data);
            break;
        case 2:
            cout << "\nHEAPIFY";
            cout << "\nEnterthe data : ";
            cin >> data;
            break;

        case 3:
            h.extract();
            break;

        case 4:

        default:
            // break;
            cout << "\nEnter the correct value! ";
        }
    } while (repeat);

    return 0;
}