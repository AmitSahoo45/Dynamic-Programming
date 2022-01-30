#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int> const &dims, int i, int j, vector<vector<int>> &lookup)
{
    if (j <= i + 1)
        return 0;

    int min = INT_MAX;

    if (lookup[i][j] == 0)
        for (int k = i + 1; k <= j - 1; k++)
        {
            int cost = matrixChainMultiplication(dims, i, k, lookup);
            cost += matrixChainMultiplication(dims, k, j, lookup);
            cost += dims[i] * dims[k] * dims[j];
            if (cost < min)
                min = cost;
        }

        lookup[i][j] = min;

    return lookup[i][j];
}

int main()
{
    vector<int> dims = {10, 30, 5, 60};
    int n = dims.size();
    vector<vector<int>> lookup(n + 1, vector<int>(n + 1));
    cout << "The minimum cost is " << matrixChainMultiplication(dims, 0, n - 1, lookup);

    return 0;
}
