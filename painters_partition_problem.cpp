#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &board, int k, int mid)
{
    int painters = 1;
    int time = 0;
    for (auto i : board)
    {
        if (time + i <= mid)
            time += i;
        else
        {
            painters++;
            if (painters > k || i > mid)
                return false;
            time = i;
        }
    }
    return true;
}
int solve(vector<int> &board, int k)
{
    int s = 0;
    int e = 0;
    for (auto i : board)
        e += i;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (e >= s)
    {
        if (isPossible(board, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> board = {10, 20, 30, 40};
    int k = 2;
    cout << solve(board, k);
}