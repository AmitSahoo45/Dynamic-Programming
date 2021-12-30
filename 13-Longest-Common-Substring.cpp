#include <bits/stdc++.h>
using namespace std;

int LCS(string x, string y, int n, int m)
{
    int t[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
            if (i == 0 || j == 0)
                t[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = 0;

    return t[n][m];
}

int main()
{

    string x, y;
    cout << "Enter first string : ";
    getline(cin >> ws, x);
    cout << "Enter second string : ";
    getline(cin >> ws, y);

    int result = LCS(x, y, x.length(), y.length());
    cout << "longest common substring : " << result << endl;

    return 0;
}