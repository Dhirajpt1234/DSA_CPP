#include <bits/stdc++.h>
using namespace std;
int fun(int x)
{
    if (x == 0)
        return 1;
    fun(x - 1);
    cout << x << " \n";
}

int main()
{
    int x = 10;

    fun(x);

    return 0;
}