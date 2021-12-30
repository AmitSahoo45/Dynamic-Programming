// Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

// length   | 1   2   3   4   5   6   7   8
// --------------------------------------------
// price    | 1   5   8   9  10  17  17  20
// And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

#include <bits/stdc++.h>
using namespace std;

int rodCuttingProblem(int price[], int n)
{
    int dp[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
                dp[i][0] = 0;
            if (j == 0)
                dp[0][j] = 1;
        }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (price[i] <= j)
                dp[i][j] = max(price[i] + dp[i][j - price[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }

    return dp[n][n];
}

int main()
{
    int n;
    cout << "Enter the length of the rod : ";
    cin >> n;

    int price[n];
    cout << "Enter the price for each of n-1 length of rod : ";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter price : ";
        cin >> price[i];
    }

    int res = rodCuttingProblem(price, n);

    return 0;
}