#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()
#define V(a, x, n, m) vector<vector<x>> a(n, vector<x>(m))

int solve(string str, int i, int j, int istrue)
{
    if (i > j)
        return 0;

    if (i == j)
    {
        if (istrue)
            return str[i] == 'T';
        else
            return str[i] == 'F';
    }

    int ans = 0;

    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int leftT = solve(str, i, k - 1, 1);
        int leftF = solve(str, i, k - 1, 0);
        int rightT = solve(str, k + 1, j, 1);
        int rightF = solve(str, k + 1, j, 0);

        if (str[k] == '^')
        {
            if (istrue)
                ans += (leftT * rightF) + (leftF * rightT);
            else
                ans += (leftT * rightT) + (leftF * rightF);
        }
        else if (str[k] == '&')
        {
            if (istrue)
                ans += (leftT * rightT);
            else
                ans += (leftT * rightF) + (leftF * rightT) + (leftF * rightF);
        }
        else if (str[k] == '|')
        {
            if (istrue)
                ans += (leftT * rightF) + (leftF * rightT) + (leftT * rightT);
            else
                ans += (leftF * rightF);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}
