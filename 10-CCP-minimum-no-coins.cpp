#include <bits/stdc++.h>
using namespace std;

int minCoins(int n, int coins[], int T, int dp[])
{

    int ans = INT_MAX;
    if (n == 0)
        return 0;

    if (dp[n] != 0)
        return dp[n];

    for (int i = 0; i < T; i++)
        if (n - coins[i] >= 0)
        {
            int subprob = minCoins(n - coins[i], coins, T, dp);
            ans = min(ans, subprob + 1);
        }

    dp[n] = ans;
    return ans;
}

int minimumnocoins(int N, int coins[], int T)
{
    int dp[100] = {0};

    for (int n = 1; n <= N; n++)
    {
        dp[n] = INT_MAX;
        for (int i = 0; i < T; i++)
            if (n - coins[i] >= 0)
            {
                int subprob = dp[n - coins[i]];
                dp[n] = min(dp[n], subprob + 1);
            }
    }
    return dp[N];
}

int main()
{
    int n;
    cout << "Enter the amount of coins you want to make change for : ";
    cin >> n;
    int coins[n];
    cout << "Enter the value for " << n << " coins : \n";
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int size = sizeof(coins) / sizeof(int);

    cout << minimumnocoins(n, coins, size) << endl;

    return 0;
}