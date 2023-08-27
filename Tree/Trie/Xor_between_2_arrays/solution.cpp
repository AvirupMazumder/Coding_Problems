#include<bits/stdc++.h>
using namespace std;
class Trie{
    public:
    Trie *zero;
    Trie *one;
    Trie()
    {
        zero=NULL;
        one=NULL;
        
    }
};
void insert(Trie *root,int num)
{
    Trie *root1=root;
    for(int i=31;i>=0;i--)
    {
        if((num>>i)&1)
        {
            if(root1->one == NULL)
            {
                root1->one=new Trie();
            }
            root1=root1->one;
        }
        else
        {
            if(root1->zero == NULL)
            {
                root1->zero=new Trie();
            }
            root1=root1->zero;
        }
    }
}
int calculate(Trie *root,vector<int> &B)
{
    int sum=0,n2=B.size();
    for(int i=0;i<n2;i++)
    {
        int max=0;
        Trie *root1=root;
        for(int j=31;j>=0;j--)
        {
            if((B[i]>>j)&1)
            {
                if(root1->zero !=NULL)
                {
                    max=max+pow(2,j);
                    root1=root1->zero;
                }
                else
                {
                    root1=root1->one;
                }
            }
            else
            {
                if(root1->one !=NULL)
                {
                    max=max+pow(2,j);
                    root1=root1->one;
                }
                else
                {
                    root1=root1->zero;
                }
            }
        }
        if(sum<max)
            sum=max;
    }
    return sum;
}
int solve(vector<int> &A, vector<int> &B) {
    Trie *root=new Trie();
    int i,n1=A.size();
    for(i=0;i<n1;i++)
    {
        insert(root,A[i]);
    }
    return calculate(root,B);
}
