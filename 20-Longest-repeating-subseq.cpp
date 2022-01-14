#include <bits/stdc++.h>
using namespace std;
int LongestRepeatingSubSeq(string str)
{
    int n = str.length();

    int t[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (i == 0 or j == 0)
                t[i][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (str[i - 1] == str[j - 1] && i != j)
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }

    return t[n][n];
}
int main()
{
    string str;
    cout << "Enter a string : ";
    getline(cin >> ws, str);
    cout << LongestRepeatingSubSeq(str);
    return 0;
}