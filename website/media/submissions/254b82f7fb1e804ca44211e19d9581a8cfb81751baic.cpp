#include <iostream>
#include <algorithm>
using namespace std;
long long t,n,k,s;

int q[100][10000];
int pos[100][10000];
int numq[100];
bool coct;
int remain;
long long s2;
int chutrinh(int n, int k)    {
              s=2;
              int i,j;
              for (i=0;i<n;i++) numq[i]=0;
              numq[2]=1;
              q[2][1] = 2;
              pos[2][1] = 1;
              //long long s2;
              coct=false;
              for (i=1; i<n+1;i++)
              {
                  s2 = (s*s) % k;
                  for (j=1; j<numq[s2%100]+1; j++)
                      if (q[s2%100][j]==s2)
                      {  coct=true;
                         remain = n - i;
                         return i - pos[s2%100][j];
                         
                         }
                   
                  s = s2;
                  numq[s2%100]++;
                  q[s2%100][numq[s2%100]] = s;
                  }
return n;
}             
int kq(int n, int k){
    
    int ct = chutrinh(n,k);
    //cout <<ct <<endl;
    if (ct >= n) return s;
    remain = remain % ct;
    int i;
    for (i=1; i < remain + 1; i++)
              s2 = (s2*s2) % k;
    return s2;
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
