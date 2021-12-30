#include <bits/stdc++.h>

using namespace std;

int findSubsetSum(int v[], int n, int sum)
{
    int arr[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                arr[i][j] = 0;
            if (j == 0)
                arr[i][j] = 1;
        }

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
            if (v[i] <= sum)
                arr[i][j] = arr[i - 1][j - v[i - 1]] + arr[i - 1][j];
            else
                arr[i][j] = arr[i - 1][j];

    return arr[n][sum];
}

int main()
{
    int n, sum = 0;
    cout << "Enter size of the array : ";
    cin >> n;
    int v[n];

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int sum_diff;
    cout << "Enter the desired sum difference between the two subsets : ";
    cin >> sum_diff;

    int f_subset = (sum + sum_diff) / 2;

    cout << "The No. of subsets with the given Sum difference is " << findSubsetSum(v, n, f_subset);

    return 0;
}