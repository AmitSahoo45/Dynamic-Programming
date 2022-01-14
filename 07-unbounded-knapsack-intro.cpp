#include <bits/stdc++.h>
using namespace std;

int knapSack(int N, int val[], int wt[])
{
    int dp[N + 1][N + 1];

    for (int i = 0; i < N + 1; i++)
        for (int j = 0; j < N + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 0;
        }

    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < N + 1; j++)
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];

    return dp[N][N];
}

int main()
{
    int N, W;
    cout << "Enter the size of value array and weight array : ";
    cin >> N;
    int val[N], wt[N];
    cout << "Enter data to the value array : \n";
    for (int i = 0; i < N; i++)
        cin >> val[i];
    cout << "Enter data to the weight array : \n";
    for (int i = 0; i < N; i++)
        cin >> wt[i];

    cout << knapSack(N, val, wt) << endl;

    return 0;
}