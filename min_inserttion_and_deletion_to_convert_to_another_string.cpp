// Author : Vikram D Singh
// Date :
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int lcs(string x, string y, int n, int m)
{
    int t[n + 1][m + 1];
    for (int i = 0; i < m + 1; i++)
        t[0][i] = 0;
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }
    return t[n][m];
}
int func(string x, string y)
{
    return x.size() + y.size() - 2 * lcs(x, y, x.size(), y.size());
}
int main()
{
    string x = "heap";
    string y = "pea";
    cout << func(x, y);
    return 0;
}