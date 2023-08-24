#include<bits/stdc++.h>
using namespace std;
#define M1 1000000007
void multiply(long int F[2][2], long int M[2][2])
{
    long int x = ((F[0][0]%M1 * M[0][0]%M1)%M1 + (F[0][1]%M1 * M[1][0]%M1)%M1)%M1;
    long int y = ((F[0][0]%M1 * M[0][1]%M1)%M1 + (F[0][1]%M1 * M[1][1]%M1)%M1)%M1;
    long int z = ((F[1][0]%M1 * M[0][0]%M1)%M1 + (F[1][1]%M1 * M[1][0]%M1)%M1)%M1;
    long int w = ((F[1][0]%M1 * M[0][1]%M1)%M1 + (F[1][1]%M1 * M[1][1]%M1)%M1)%M1;
     
    F[0][0] = x%M1;
    F[0][1] = y%M1;
    F[1][0] = z%M1;
    F[1][1] = w%M1;
}
void power(long int F[2][2], int n)
{
    if(n == 0 || n == 1)
       return;
    long int M[2][2] = {{1, 1}, {1, 0}};
     
    power(F, n / 2);
    multiply(F, F);
     
    if (n % 2 != 0)
        multiply(F, M);
}
int solve(int n) {
    long int F[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
 
    return F[0][0];
}
int main()
{
  int n;
  cin>>n;
  cout<<solve(n);
  return 0;
}
