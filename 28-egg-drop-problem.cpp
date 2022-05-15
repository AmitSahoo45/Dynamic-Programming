#include <bits/stdc++.h>
using namespace std;

int t[201][201];

int solve(int e, int f)
{
    int low, high, temp;
    if (f == 0 || f == 1)
        return f;

    if (e == 1)
        return f;

    int mn = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        if (t[e - 1][k - 1] != -1)
            low = t[e - 1][k - 1];
        else
        {
            low = solve(e - 1, k - 1);
            t[e - 1][k - 1] = low;
        }
        if (t[e][f - k] != -1)
            high = t[e][f - k];
        else
        {
            high = solve(e, f - k);
            t[e][f - k] = high;
        }
        temp = 1 + max(low, high);
        mn = min(mn, temp);
    }
    return mn;
}
int eggDrop(int e, int f)
{
    for (int i = 0; i < 201; i++)
        for (int j = 0; j < 201; j++)
            t[i][j] = -1;

    return solve(e, f);
}

int main()
{

    return 0;
}