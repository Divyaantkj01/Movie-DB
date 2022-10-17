// Author : Vikram D Singh
// Date :
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(int i, int n, vector<vector<int>> &board, vector<vector<int>> &ans, vector<int> &col, vector<int> &tl, vector<int> &tr)
{
    if (i >= n)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                temp.push_back(board[i][j]);
        }
        ans.push_back(temp);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (col[j] == 0 && tl[i - j + n - 1] == 0 && tr[i + j] == 0)
        {
            board[i][j] = 1;
            col[j] = tl[i - j + n - 1] = tr[i + j] = 1;
            solve(i + 1, n, board, ans, col, tl, tr);
            board[i][j] = 0;
            col[j] = tl[i - j + n - 1] = tr[i + j] = 0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
            temp.push_back(0);
        board.push_back(temp);
    }
    vector<int> tl(2 * n, 0);
    vector<int> tr(2 * n, 0);
    vector<int> col(n, 0);
    solve(0, n, board, ans, col, tl, tr);
    return ans;
}
int main()
{
    int n = 4;
    vector<vector<int>> ans = nQueens(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}