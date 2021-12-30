#include <bits/stdc++.h>
using namespace std;

static int dp[0][0];

bool isSubsetSum(int arr[], int n, int sum)
{
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }

    // iterative knapsack method
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
                // cout << "j : " << j << "\tarr[i-1] : " << arr[i - 1] << "\tdiff : " << j - arr[i - 1] << "\n";
            }
            else
                dp[i][j] = dp[i - 1][j];
        }

    return dp[n][sum];
}
int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;
    int arr[n];
    cout << "Enter data into array : \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cout << "Enter sum : ";
    cin >> sum;

    dp[n][sum];

    if (isSubsetSum(arr, n, sum))
        cout << "Yes, Subset is present\n";
    else
        cout << "No, Subset is present\n";

    return 0;
}