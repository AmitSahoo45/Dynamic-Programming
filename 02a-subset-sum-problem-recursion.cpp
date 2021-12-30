#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum)
{
    if (sum == 0)
        return true;

    if (n == 0)
        return false;

    if (sum < arr[n - 1])
        return isSubsetSum(arr, n - 1, sum);

    return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum;
    cin >> sum;

    if (isSubsetSum(arr, n, sum))
        cout << "Yes Subset is present\n";
    else
        cout << "No Subset is present\n";

    return 0;
}