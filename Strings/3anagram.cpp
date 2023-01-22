#include <bits/stdc++.h>
using namespace std;
bool anagram(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    else
    {
        int ans[128] = {0};
        int len = a.length();

        for (int i = 0; i < len; i++)
        {
            ans[int(a[i])]++;
        }

        for (int i = 0; i < len; i++)
        {
            ans[int(b[i])]--;
        }

        for (int i = 0; i < 128; i++)
        {
            if (ans[i] != 0)
            {

                return false;
            }
        }
        return true;
    }
}
int main()
{
    string a, b;
    cout << "Enter the strings : ";
    cin >> a >> b;

    if (anagram(a, b))
    {
        cout << "this is anagram !\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}