#include<bits/stdc++.h>
using namespace std;
int maximumSumTriplet(vector<int> &A) {
    int i,j,n=A.size();
    int ans=0;
    set<int> lowerval;
    int *auxArry=new int[n+1];
    auxArry[n]=0;
    for(i=n-1;i>=0;i--)
    {
        auxArry[i]=(A[i]>auxArry[i+1])?A[i]:auxArry[i+1];
    }
    lowerval.insert(0);
    lowerval.insert(A[0]);
    for(i=1;i<n-1;i++)
    {
        lowerval.insert(A[i]);
        auto it=lowerval.find(A[i]);
        --it;
        if(A[i]<auxArry[i+1] && *it>0)
        {
            int t=*it+A[i]+auxArry[i+1];
            ans=(ans<t)?t:ans;
        }
    }
    return ans;
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
    cout<<maximumSumTriplet(A)<<endl;
    return 0;
}
