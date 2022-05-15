#include <bits/stdc++.h>
using namespace std;

int dp[2001][2001];

bool isplaindrome(string str, int i, int j)
{
    while (i <= j)
    {
        if (str[i] == str[j])
            return false;
        i++, j--;
    }
    return true;
}

int solve(string &s, int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (isplaindrome(s, i, j))
        return 0;

    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        if (isplaindrome(s, k + 1, j))
        {
            int temp = 1 + solve(s, k + 1, j);
            mn = min(temp, mn);
        }
    }
    return dp[i][j] = mn;
}

int palindromePartitioning(string s)
{
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, s.size() - 1);
}

int main()
{
    string str;
    getline(cin >> ws, str);

    int partition = palindromePartitioning(str);
    cout << "Total No. of Partitions to be made : " << partition << endl;

    return 0;
}