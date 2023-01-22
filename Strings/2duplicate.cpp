#include <bits/stdc++.h>
using namespace std;
void duplicate(string s)
{
    int len = s.length();
    int ans[27] = {0};
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            ans[s[i] - 65]++;
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            ans[s[i] - 97]++;
        }
    }

    for (int i = 0; i < 27; i++)
    {
        if (ans[i] > 1)
        {
            cout << char('a' + i) << " is repeating "<<ans[i]<<" times\n";
        }
    }
}

int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;

    duplicate(s);

    return 0;
}