#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (x[n - 1] == y[m - 1])
        return 1 + lcs(x, y, n - 1, m - 1);
    else
        return max(lcs(x, y, n, m - 1), lcs(x, y, n - 1, m));
}
int main()
{
    string s1, s2;
    cout << "Enter first string : ";
    getline(cin >> ws, s1);
    cout << "Enter second string : ";
    getline(cin >> ws, s2);
    int res = lcs(s1, s2, s1.length(), s2.length());

    cout << "Length of the Longest Common Subsequence : " << res << endl;

    return 0;
}
