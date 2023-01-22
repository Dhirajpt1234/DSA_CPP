#include <bits/stdc++.h>
using namespace std;

int fun(int a, int n)
{
    if (n == 1)
        return a;

    return a * fun(a, (n - 1));
}
int main()
{

    int a, n;
    cout << "Enter the a and n : ";
    cin >> a >> n;

    cout << fun(a, n);

    return 0;
}