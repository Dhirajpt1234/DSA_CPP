#include <bits/stdc++.h>
using namespace std;
int fun(int n)
{
    if (n == 0)
    {
        return 1;
    }
    cout << n << " ";
    fun(n - 1);
    fun(n - 1);
}
int main()
{
    int n = 3;
    // cout << "Enter the no: ";
    // cin >> n;

    cout << fun(n);

    return 0;
}