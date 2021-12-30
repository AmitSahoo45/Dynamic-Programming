// PRINTING THE LONGEST COMMON SUBSEQUENCE

#include <bits/stdc++.h>
using namespace std;

string LCS(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i] == y[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    int i = n, j = m;
    string s = "";
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }
    // if (i != 0)
    // {
    //     while (i > 0)
    //     {
    //         s.push_back(x[i]);
    //         i--;
    //     }
    // }
    // else if (j != 0)
    // {
    //     while (j > 0)
    //     {
    //         s.push_back(y[j]);
    //         j--;
    //     }
    // }

    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    string x, y;
    cout << "Enter first string : ";
    getline(cin >> ws, x);
    cout << "Enter second string : ";
    getline(cin >> ws, y);

    string result = LCS(x, y, x.length(), y.length());
    cout << "Printing the Shortest Common Subsequence : " << result << endl;

    return 0;
}