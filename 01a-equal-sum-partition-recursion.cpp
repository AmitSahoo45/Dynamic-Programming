#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum)
{
    if (sum == 0)
        return true;

    if (n == 0)
        return false;

    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum);

    return isSubsetSum(arr, n - 1, sum - arr[n - 1]) || isSubsetSum(arr, n - 1, sum);
}

int main()
{
    int n;
    cin >> n;
    int arr[n], sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % 2 != 0)
        cout << "Equal sum partition is not possible\n";
    else
    {
        if (isSubsetSum(arr, n, sum) == true)
            cout << "Yes, Array can be divided into two equal parts\n";
        else
            cout << "No, Array can't be divided into two equal parts\n";
    }
    return 0;
}