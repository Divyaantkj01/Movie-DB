#include <bits/stdc++.h>
using namespace std;

void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);//Push the empty value of the ds and the subsets henceforth everytime the loop ends. 
    for (int i = ind; i < nums.size(); i++) //Start from the index and traverse to the end
    {
        if (i != ind && nums[i] == nums[i - 1]) //If the prev and current elements are same or if they are not at the same index then we can continue because if we want to pick duplicate index's,it should be the first time that we are reaching that element, for it to happen i and index should be same.
        {
            continue;
        }
        ds.push_back(nums[i]); //Pick the element and dive in the recursion with increment in index
        findSubsets(i+ 1, nums, ds, ans);
        ds.pop_back(); //Now the remove the element
    }
}

vector<vector<int>> subsetsWithDup(vector<int> nums)
{
    vector<vector<int>> ans; //To store our final answer
    vector<int> ds; // A data structure to store all the possible subsets in every recursion
    sort(nums.begin(), nums.end()); //sort the given array in order for our algo to work
    findSubsets(0, nums, ds, ans);
    return ans;
}
int main()
{

    return 0;
}