#include <iostream>
#include <algorithm>
using namespace std;
long long t,n,k;
int cs;
int q[100][10000];
int pos[100][10000];
int numq[100];
bool coct;
int remain;
long long s2;
int chutrinh(int n, int k)    {
              int i,j;
              for (i=0;i<cs;i++) numq[i]=0;
              numq[2]=1;
              q[2][1] = 2;
              pos[2][1] = 1;
              s2 = 2;
              //long long s2;
              coct=false;
              for (i=1; i<n+1;i++)
              {
                  s2 = (s2*s2) % k;
                  for (j=1; j<numq[s2%cs]+1; j++)
                      if (q[s2%cs][j]==s2)
                      {  coct=true;
                         remain = n - i;
                         return i - pos[s2%cs][j];
                         
                         }
                   
                  numq[s2%cs]++;
                  q[s2%cs][numq[s2%cs]] = s2;
                  }
return n;
}             
int kq(int n, int k){
    if (k==0) return 0;
    int ct = chutrinh(n,k);
    //cout <<ct <<endl;
    if ((ct >= n) || (ct==0)) return s2;
    remain = remain % ct;
    int i;
    for (i=1; i < remain + 1; i++)
              s2 = (s2*s2) % k;
    return s2;
}
                
      

int main() 
{
    cs=100;
    cin >>t;
    int i;
    for (i=1; i<t+1; i++)
        {
              cin >> n >>k;
              cout << kq(n,k) <<endl;

                  
              }
    return 0;

}
