#include <bits/stdc++.h>

using namespace std;

int static dp[10001][10001];

int LCS(string x, string y, int n, int m)
{

    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (x[n - 1] == y[m - 1])
        return dp[n][m] = 1 + LCS(x, y, n - 1, m - 1);
    else
        return dp[n][m] = max(LCS(x, y, n, m - 1), LCS(x, y, n - 1, m));
}

int main()
{
    memset(dp, -1, sizeof(dp));

    string x, y;
    cout << "Enter first string : ";
    getline(cin >> ws, x);
    cout << "Enter second string : ";
    getline(cin >> ws, y);

    int result = LCS(x, y, x.length(), y.length());
    cout << "longest common subsequence : " << result << endl;

    return 0;
}