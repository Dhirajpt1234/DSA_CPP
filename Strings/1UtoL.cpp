#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] += 32;
        }
    }
    cout << "The lower case string is : " << s;

    return 0;
}