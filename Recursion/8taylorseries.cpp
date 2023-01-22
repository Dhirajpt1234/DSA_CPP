#include <bits/stdc++.h>
using namespace std;
int tay(int a, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        p = a;
        f = f + 1;
        r = 1 + p / f;
        return r * tay(a, n - 1);
        }
}
int main()
{
    int a, n;
    cout << "Enter the a and n : ";
    cin >> a >> n;

    cout << tay(a, n);

    return 0;
}