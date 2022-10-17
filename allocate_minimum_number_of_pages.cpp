// Author : Vikram D Singh
// Date :
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool isPossible(vector<int> &pages, int n, int m, int mid){
    int count = 1;
    int pageSum = 0;
    for(int i: pages){
        if(pageSum + i <= mid)
            pageSum += i;
        else{
            count++;
            if(count > m || i > mid)
                return false;
            pageSum = i;
        }
    }
    return true;
}
int solve(vector<int> &pages, int n, int m){
    int s = 0;
    int e = 0;
    for(int i: pages)
        e += i;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while(e >= s){
        if(isPossible(pages, n, m, mid)){
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
    vector<int> pages = {12, 34, 67, 90};
    int m = 2;
    cout << solve(pages, pages.size(), m);
    return 0;
}