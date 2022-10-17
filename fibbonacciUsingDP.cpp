#include <bits/stdc++.h>
using namespace std;

int fibonacciTabulationOptimised(int n)
{
    int prev2= 0 ;
    int prev =1 ;
    for(int i=2; i<=n;i++)
    {
        int cur_i=  prev2+prev ;
        prev2 = prev ;
        prev = cur_i ;
    }
    return prev ;
    //*TC: O(n)
    //*SC: O(1)
}
/*
*Steps to convert Recursive Solution to Tabulation one.

*Declare a dp[] array of size n+1.
*First initialize the base condition values, i.e i=0 and i=1 of the dp array as 0 and 1 respectively.
*Set an iterative loop which traverses the array( from index 2 to n) and for every index set its value as dp[i-1] + dp[i-2].
*/ 

int fibonacciTabulation(int n, vector<int> &dp)
{
    //*Tabulation: Known as the “bottom-up ” dynamic programming, usually the problem is solved in the direction of solving the base cases to the main problem
    dp[0]=0 ;dp[1] =1 ;
    for(int i=2 ;i<=n;i++)
    {
        dp[i]==dp[i-1]+dp[i-2]; 
    }
    return dp[n] ;
    //*TC: O(n)
    //*SC:O(1)

}

int fibonacciMemoization(int n, vector<int> &dp)
{
    //*Memoization: Known as the “top-down” dynamic programming, usually the problem is solved in the direction of the main problem to the base cases.
    if (n <= 1)
    {
        return n;
    }
    // Step1: if the result of a sub problem is stored, return that sub problem
    if (dp[n] != -1)
    {
        return dp[n];
    }
    // store the result of the subproblem in the dp vector so it can be used in case the same sub problem resurfaces.
    return dp[n] = fibonacciMemoization(n - 1, dp) + fibonacciMemoization(n - 2, dp);

    //*TC: O(n)he overlapping subproblems will return the answer in constant time O(1). Therefore the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).
    //*SC: O(n)+O(n) ≈ O(N) We are using a recursion stack space(O(N)) and an array (again O(N)). Therefore total space complexity will be
}

int main()
{
    int n;
    cin >> n;
    // Declare a dp vector of size n+1 and initialize it with -1
    vector<int> dp(n + 1, -1);
    cout << fibonacciMemoization(n, dp)<<endl;
    cout << fibonacciTabulation(n, dp)<<endl;
    cout << fibonacciTabulationOptimised(n)<<endl;
    return 0;
}