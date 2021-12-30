#include <bits/stdc++.h>
using namespace std;

class Knapsack
{
public:
    bool dp[101][10001], flag = false;

    void initialise(int n, int arr[], int sum, bool flag)
    {
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        flag = true;
    }

    bool isSubsetSum(int arr[], int n, int sum)
    {
        if (sum == 0)
            return true;

        if (n == 0)
            return false;

        if (flag == false)
        {
            initialise(n, arr, sum, flag);
        }

        if (arr[n - 1] > sum)
            return dp[n][sum] = isSubsetSum(arr, n - 1, sum);

        return dp[n][sum] = isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
    }
};

int main()
{
    int n, sum;
    int *arr;
    cout << "Enter Size : ";
    cin >> n;
    arr = new int[n];

    cout << "Enter elements into array : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter Sum : ";
    cin >> sum;
    Knapsack ss;
    if (ss.isSubsetSum(arr, n, sum))
        cout << "Yes, Subset is present\n";
    else
        cout << "No, Subset is present\n";

    return 0;
}