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
  string temp=to_string(C);
  if(A.size()==0){
    return 0;
  }
  if(C==0){
    return 0;
  }
  if(B>temp.size()){
    return 0;
  }
  else if(B<temp.size()){
    if(A[0]==0){
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
    while(i<temp.size()){
      bool intPresent=false;
      int j=BS(temp[i]-48,A);
      if(j==-1){
        return ans;
      }
      if(A[j]==(temp[i]-48)){
        intPresent=true;
        j--;
      }
      if(i==0){
        if(A[0]==0){
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
      if(!intPresent){
        return ans;
      }
      i++;
    }
    return ans;
  }
}
