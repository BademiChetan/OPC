#include <iostream>
#include <algorithm>
using namespace std;
long long t,n,k,s;
int q[100000];
int numq;
int chutrinh(int n, int k)    {
              s=2;
              numq=1;
              q[1] = 2;
              long long s2;
              int i,j;
              for (i=1; i<n+1;i++)
              {
                  s2 = (s*s) % k;
                  for (j=1; j<numq+1; j++)
                      if (q[j]==s2)
                         return numq - j +1;
                  s = s2;
                  numq++;
                  q[numq] = s;
                  }
return n;
}             
int kq(int n, int k){
    
    int ct = chutrinh(n,k);
    //cout <<ct;
    if (numq >= n) return s;
    n = (n+1-numq)%ct;
    if (n==0) return s;
    else
    return q[numq - ct+ n];
}
                
      

int main() 
{
    cin >>t;
    int i;
    for (i=1; i<t+1; i++)
        {
              cin >> n >>k;
              cout << kq(n,k) <<endl;

                  
              }
    return 0;

}
