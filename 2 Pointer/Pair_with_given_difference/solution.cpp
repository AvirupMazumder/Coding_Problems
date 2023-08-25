#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int i=1,j=0;
    while(i<A.size() && j<A.size())
    {
        if(i!=j && A[i]-A[j]==B)
            return 1;
        else if(A[i]-A[j]<B)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return 0;
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
    cout<<solve(A,B);
}
