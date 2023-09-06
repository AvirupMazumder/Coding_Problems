#include<bits/stdc++.h>
using namespace std;
string simplifyPath(string A) {
    vector<string> node;
    int i=0,j=1;
    string path="";
    while(j<A.length())
    {
        if(A[j] == '/')
        {
            if(A.substr(i,j-i).compare("/..")==0)
            {
                if(!node.empty())
                    node.pop_back();
            }
            else if(A.substr(i,j-i).compare("/")!=0 && A.substr(i,j-i).compare("/.")!=0)
            {
                node.push_back(A.substr(i,j-i));
            }
            i=j;
        }
        else if(j==A.length()-1)
        {
            if(A.substr(i,j-i+1).compare("/..")==0)
            {
                if(!node.empty())
                    node.pop_back();
            }
            else if(A.substr(i,j-i+1).compare("/")!=0 && A.substr(i,j-i+1).compare("/.")!=0)
            {
                node.push_back(A.substr(i,j-i+1));
            }
            i=j;
        }
        j++;
    }
    if(node.empty())
        path="/";
    else{
        for(int i=0;i<node.size();i++)
        {
            path.append(node[i]);
        }
    }
    return path;
}
int main()
{
  string s;
  cin>>>s;
  cout<<simplifyPath(s)<<endl;
  return 0;
}
