#include <bits/stdc++.h>
using namespace std;
int LCS(string X, string Y)
{
    int m = X.size();
    int n = Y.size();
    int t[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;

    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }

    return t[m][n];
}

int main()
{
    string x;
    cout << "Enter a String : ";
    getline(cin >> ws, x);

    string y = x;
    reverse(x.begin(), x.end());

    int len = LCS(x, y);
    int m = x.size();

    cout << "Minimum number of insertion in a string to make it a palindrome : " << m - len;

    return 0;
}