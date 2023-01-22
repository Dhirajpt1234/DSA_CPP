#include <bits/stdc++.h>
using namespace std;

class Diagonal
{
    int size;
    int *A;

public:
    Diagonal()
    {
        size = 2;
        A = new int[size];
    }
    Diagonal(int n)
    {
        size = n;
        A = new int[n];
    }

    ~Diagonal()
    {
        delete[] A;
    }

    void set(int x, int y, int n);
    int get(int x, int y);
    void display();
};

void Diagonal ::set(int x, int y, int n)
{
    if (x == y)
    {
        A[x - 1] = n;
    }
}

int Diagonal ::get(int x, int y)
{
    if (x == y)

        return A[x - 1];
    else
        return 0;
}

void Diagonal::display()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                cout << A[i - 1] << " ";
            }
            else
                cout << 0 << " ";
        }
        cout<<"\n";
    }
}

int main()
{
    Diagonal dm(3);
    dm.set(1, 1, 34);
    dm.set(2, 2, 876);
    dm.set(0, 0, 87);

    cout << dm.get(2, 2)<<endl;
    dm.display();

    return 0;
}