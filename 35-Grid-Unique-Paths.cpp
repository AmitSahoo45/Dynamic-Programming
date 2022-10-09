#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()
#define V(a, x, n, m) vector<vector<x>> a(n, vector<x>(m))

class Solution
{
public:
    int paths(int i, int j, vector<vector<int>> dp)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = paths(i - 1, j, dp);
        int right = paths(i, j - 1, dp);

        return dp[i][j] = left + right;
    }

    int tabulation(int m, int n)
    {
        int dp[m][n];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i)
            dp[i][0] = 0;

        for (int j = 0; j < n; ++j)
            dp[0][j] = 0;

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
            {
                int left = 0, up = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }

        return dp[m - 1][n - 1];
    }

    int tabulation(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int tabs(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(m - 1, n - 1, dp);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution s;
    cout << s.uniquePaths(9, 9);

    return 0;
}
