#include <bits/stdc++.h>
using namespace std;
int taylor(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    else
    {
        r = taylor(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / r;
    }
}
int main()
{
    int x, n;
    cout << "Enter the no: ";
    cin >> x >> n;

    cout << taylor(x, n);

    return 0;
}