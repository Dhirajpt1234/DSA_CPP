#include <bits/stdc++.h>
using namespace std;
class Lower
{
    int size;
    int *A;

public:
    Lower()
    {
        size = 2;
        A = new int[3];
    }
    Lower(int n)
    {
        size = n;
        A = new int[n*(n+1)/2];
    }
    void setSize(int n);
    void set(int n);
    int get(int i, int j);
    void display();
};

void Lower::set(int n)
{
    int i = n, j = n;
    int x;
    cout << "Enter the elements of the matrix ";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> x;
            if (i == j || i > j)
            {

                A[((i * (i - 1) / 2) + j - 1)] = x;
            }
        }
    }
}

int Lower::get(int i, int j)
{
    if (i == j || i > j)
    {
        return A[((i * (i - 1) / 2) + j - 1)];
    }
    else
        return 0;
}

void Lower::display()
{
    for (int i = 0; i < size; i++)

    {
        for (int j = 0; j < size; j++)
        {
            if (i == j || i > j)
            {
                cout << A[(i * (i - 1) / 2) + j - 1] << " ";
            }
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}
int main()
{
    cout << "enter the size of matrix ";
    int n;
    cin >> n;
    Lower l(n);

    l.set(n);

    cout << l.get(2, 3) << endl;

    l.display();

    return 0;
}