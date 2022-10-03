#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()
#define V(a, x, n, m) vector<vector<x>> a(n, vector<x>(m))

class Solution
{
public:
    int countDistinctWayToClimbStair(ll n)
    {
        // dynamic programming approach
        if (n == 0 || n == 1)
            return 1;
        if (n == 2)
            return 2;
        ll dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }

    int array[46];
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
            return 1;

        if (array[n] != 0)
            return array[n];
        else
        {
            array[n] = climbStairs(n - 1) + climbStairs(n - 2);
            return array[n];
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution s;
    // cout << s.countDistinctWayToClimbStair(3) << endl;
    cout << s.climbStairs(3) << endl;

    return 0;
}
