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
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int B;
    cin>>B;
    cout<<solve(A,B)<<endl;
    return 0;
}