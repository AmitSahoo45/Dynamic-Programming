#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

void lcs(string x, string y, int m, int n)
{
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
}

string scs(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    int dp[m][n];
    lcs(X, Y, m, n);
    string ans;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            ans.push_back(X[i - 1]);
            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            ans.push_back(Y[j - 1]);
            j--;
        }
        else
        {
            ans.push_back(X[i - 1]);
            i--;
        }
    }
    while (i > 0)
    {
        ans.push_back(X[i - 1]);
        i--;
    }
    while (j > 0)
    {
        ans.push_back(Y[j - 1]);
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string x, y;
    cout << "Enter the first string : ";
    getline(cin >> ws, x);
    cout << "Enter the second string : ";
    getline(cin >> ws, y);
    cout << "Shortest common supersequence is : " << scs(x, y) << endl;
    return 0;
}