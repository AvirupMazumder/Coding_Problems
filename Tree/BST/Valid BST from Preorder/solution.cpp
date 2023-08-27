/*
    The idea is to use a stack. This problem is similar to Next (or closest) Greater Element problem.
Here we find the next greater element and after finding next greater, if we find a smaller element, then return false.

    1. Create an empty stack.
    2. Initialize root as INT_MIN.
    3. Do following for every element pre[i]
       a. If pre[i] is smaller than current root, return false.
       b.  Keep removing elements from stack while pre[i] is greater
        then stack top. Here check for any duplicate elements while comparing pre[i]
        with stack top, return false.Make the last removed item as new root (to
        be compared next).
        At this point, pre[i] is greater than the removed root
        (That is why if we see a smaller element in step a), we
        return false)
       c. push pre[i] to stack (All elements in stack are in decreasing
        order)
*/
#include<bits/stdc++.h>
using namespace std;
int canRepresentBST(vector<int> pre)
{
    int n=pre.size();
    // Create an empty stack
    stack<int> s;
 
    // Initialize current root as minimum possible
    // value
    int root = INT_MIN;
 
    // Traverse given array
    for (int i=0; i<n; i++)
    {
        // If we find a node who is on right side
        // and smaller than root, return false
        if (pre[i] < root)
            return 0;
 
        // If pre[i] is in right subtree of stack top,
        // Keep removing items smaller than pre[i]
        // and make the last removed item as new
        // root.
        while (!s.empty() && s.top()<=pre[i])
        {
            //No duplicates allowed in BST
            if(s.top()==pre[i])
            {
                return 0;
            }
            root = s.top();
            s.pop();
        }
 
        // At this point either stack is empty or
        // pre[i] is smaller than root, push pre[i]
        s.push(pre[i]);
    }
    return 1;
}

int solve(vector<int> &A) {
    return canRepresentBST(A);
}
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<solve(A);
    return 0;
}
