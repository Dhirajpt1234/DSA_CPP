#include <bits/stdc++.h>
using namespace std;
int fun(int x)
{
    static int n = 0;
    if(x>0)
    {
        n++;
        return fun(x-1) + n;
    }
    return 0;
}

int main()
{
    int x = 10;

    cout<<fun(x)<<endl;

    return 0;
}