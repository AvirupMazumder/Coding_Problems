#include<bits/stdc++.h>
using namespace std;
int countingSubArrays(vector<int> &A,int B)
{
    int i=0,j=0;
    int sum=0,count=0;
    while(i<A.size() && j<A.size())
    {
        sum+=A[j];
        while(sum>=B && i<=j)
        {
            sum-=A[i];
            i++;
        }
        count+=j-i+1;
        j++;
    }
    return count;
}

int solve(vector<int> &A, int B) {
    return countingSubArrays(A,B);
}

int main()
{
