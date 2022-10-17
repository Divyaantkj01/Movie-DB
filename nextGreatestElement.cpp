#include <bits/stdc++.h> /*Next Greater Element of elements in an array.*/
using namespace std;
void PrintNGE_by_bruteforce(int arr[], int n) /*This is brute force approach and takes O(n^2) time*/
{
    for (int i = 0; i < n; i++)
    {
        int next = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << "NGE (" << arr[i] << ") --> " << next << endl;
    }
}

void PrintNGE_by_stack(int arr[], int n) /*This is an approach of the problem using stack. This takes O(n) time to execute which is very better than using brute force.*/
{
    stack<int> s;               /*Create a stack using 
    C++ template*/
    s.push(arr[0]);             /*Push the first element in the stack.*/
    for (int i = 1; i < n; i++) /*Run the loop from the next element of array and iterate to the end element of the element  */
    {
        // if (s.empty())
        // {
        //     s.push(arr[i]) ;
        //     continue ;
        // }
        while (!s.empty() && s.top() < arr[i]) /* if stack is not empty, then
           pop an element from stack.
           If the popped element is smaller
           than next, then
        a. print the pair
        b. keep popping while elements are
        smaller and stack is not empty */
        {
            cout << "NGE (" << s.top() << ") --> " << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]); /* push next to stack so that we can find
        next greater for it */
    }
    /* After iterating over the loop, the remaining
    elements in stack do not have the next greater
    element, so print -1 for them */
    while (!s.empty())
    {
        cout << "NGE (" << s.top() << ") --> " << -1 << endl;
        s.pop();
    }
}

int main()
{
    cout << "Enter the size of array" << endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The solution by brute force approach:" << endl;
    PrintNGE_by_bruteforce(arr, n);

    cout << "The solution by using stack approach:" << endl;
    PrintNGE_by_stack(arr, n);

    return 0;
}
