#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, j;

    int t[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (wt[i - 1] <= j)
                t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][W];
}

// Driver Code
int main()
{
    int n = 0;
    cout << "Enter value of size array : ";
    cin >> n;
    int val[n], int wt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value : ";
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value : ";
        cin >> wt[i];
    }
    int W;
    cout << "Enter the weight : ";
    cin >> W;
    
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(W, wt, val, n);

    return 0;
}