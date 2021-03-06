#include <bits/stdc++.h>
using namespace std;

bool LongestCommonSubsequence(string X, string Y)
{
    int m = X.size();
    int n = Y.size();

    int t[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;

    for (int i = 1; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }

    if (t[m][n] == m)
        return true;

    return false;
}

int main()
{
    string x, y;
    cout << "Enter the first string : ";
    getline(cin >> ws, x);
    cout << "Enter the second string : ";
    getline(cin >> ws, y);

    cout << LongestCommonSubsequence(x, y) << "\n";

    return 0;
}