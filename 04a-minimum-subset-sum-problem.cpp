#include <bits/stdc++.h>

using namespace std;

int minimumSubset(vector<int> v, int sum)
{
    int s = sum / 2;
    int n = v.size();
    int dp[n + 1][s + 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < s; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < s + 1; j++)
        {
            if (v[i - 1] < j)
                dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }

    int i;
    for (int j = 0; j <= s; j++)
        if (dp[n][j])
            i = j;

    return (sum - 2 * i);
}

int main()
{
    vector<int> v;
    int n, sum = 0;
    cout << "Enter vector size : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter value : ";
        cin >> x;
        v.push_back(x);
        sum += x;
    }

    int res = minimumSubset(v, sum);

    cout << "Minimum Subset Sum difference : " << res << endl;

    return 0;
}