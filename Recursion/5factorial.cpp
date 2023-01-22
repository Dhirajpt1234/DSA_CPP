#include <bits/stdc++.h>
using namespace std;

int fun(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n* fun(n - 1);
}
int main()
{
    int n;
    cout << "Enter the no: ";
    cin>>n;

    cout << fun(n);

    return 0;
}









