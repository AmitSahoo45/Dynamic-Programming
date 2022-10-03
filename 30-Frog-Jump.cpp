#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001];
    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }

    int recursiveWay(vector<int> &stones, int n)
    {
        if (n == 0)
            return 0;

        int left = recursiveWay(stones, n - 1) + abs(stones[n] - stones[n - 1]);
        int right = INT_MAX;

        if (n > 1)
            right = recursiveWay(stones, n - 2) + abs(stones[n] - stones[n - 2]);

        return min(left, right);
    }

    int recursiveMemo(vector<int> &stones, int n)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int left = recursiveWay(stones, n - 1) + abs(stones[n] - stones[n - 1]);
        int right = INT_MAX;

        if (n > 1)
            right = recursiveWay(stones, n - 2) + abs(stones[n] - stones[n - 2]);

        return dp[n] = min(left, right);
    }

    int tabulation(vector<int> &stones, int n)
    {
        vector<int> t(n, 0);
        t[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int fs = t[i - 1] + abs(stones[i] - stones[i - 1]);
            int ss = INT_MAX;
            if (i > 1)
                ss = t[i - 2] + abs(stones[i] - stones[i - 2]);

            t[i] = min(fs, ss);
        }
        return dp[n - 1];
    }

    int spaceOptimization(vector<int> &stones, int n)
    {
        int prev = 0, prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int fs = prev + abs(stones[i] - stones[i - 1]);
            int ss = INT_MAX;
            if (i > 1)
                ss = prev2 + abs(stones[i - 1] - stones[i - 2]);

            int cur = min(fs, ss);
            prev2 = prev;
            prev = cur;
        }

        return prev;
    }

    void frogJump()
    {
        vector<int> stones{30, 10, 60, 10, 60, 50};
        int len = stones.size();
        cout << "Recusive Way\n";
        cout << recursiveWay(stones, len - 1) << endl;
        cout << "Recusive + Memoization\n";
        cout << recursiveMemo(stones, len - 1) << endl;
        cout << "Tabulation Format\n";
        cout << tabulation(stones, len) << endl;
        cout << "Space Optimization\n";
        cout << spaceOptimization(stones, len) << endl;
    }
};

int main()
{
    Solution s;
    s.frogJump();

    return 0;
}