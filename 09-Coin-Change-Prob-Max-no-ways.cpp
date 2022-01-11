#include <bits/stdc++.h>
using namespace std;

long long int count(int S[], int m, int n)
{
    long long int dp[m + 1][n + 1];
    // Init
    for (int i = 0; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }

    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
            if (S[i - 1] <= j)
                dp[i][j] = dp[i][j - S[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[m][n];
}

int main()
{

    int n, m;
    cin >> n;
    cin >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    count(arr, n, m);
    
    return 0;
}