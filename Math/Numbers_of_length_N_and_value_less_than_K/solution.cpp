#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int num,vector<int> A){
  int l=0;
  int r=A.size()-1;
  while(l<=r){
      int flag=l+(r-l)/2;
      if(A[flag]==num){
          return flag;
      }
      else if(A[flag]<num){
          if(flag==A.size()-1){
              return flag;
          }
          else if(A[flag+1]>num){
              return flag;
          }
          else{
              l=flag+1;
          }
      }
      else{
          r=flag-1;
      }
  }
  return -1;
}

int solve(vector<int> &A, int B, int C) {
  int ans=0;
  string str=to_string(C);
  if(A.size()==0){
    return 0;
  }
  if(C==0){
    return 0;
  }
  if(B>str.size()){
    return 0;
  }
  else if(B<str.size()){
    if(A[0]==0){
      //Number cannot start with 0 hence excluding 0 at the 1st position  
      ans+=pow(A.size(),B-1)*(A.size()-1);
      if(B==1){
        ans++;
      }
      return ans;
    }
    else{
      return pow(A.size(),B);
    }
  }
  else{
    int i=0;
    while(i<str.size()){
      //ifPresent is a boolean variable to store whether the digits present in String str is present in vector A or not  
      bool ifPresent=false;

      //j denotes the number of digits in vector A that is less than or equal to the character at I th position
      int j=BinarySearch(str[i]-48,A);
      if(j==-1){
        return ans;
      }
      if(A[j]==(str[i]-48)){
        ifPresent=true;
        j--;
      }
      if(i==0){
        if(A[0]==0){
          //Number cannot start with 0 hence excluding 0 at 1st position  
          ans+=((j)*pow(A.size(),B-1-i));
          if(B==1){
            ans++;
          }
        }
        else{
          ans+=(j+1)*pow(A.size(),B-1-i);
        }
      }
      else{
        ans+=(j+1)*pow(A.size(),B-1-i);
      }
      if(ifPresent==false){
        return ans;
      }
      i++;
    }
    return ans;
  }
}

int main()
{
    int B,C;
    int n;
    int i;
    cin>>n;
    vector<int> A(n);
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cin>>B>>C;
    cout<<solve(A,B,C)<<endl;
    return 0;
}
