#include<iostream>

using namespace std;

int main()
{
  int T,N[10],K[10],i,j,k,sum,count;
  
  do { cin>>T; } while(T<1 || T>1000);
  for(i=0;i<T;i++)
  {
    do { cin>>N[i]; } while(N[i]<1);
    do { cin>>K[i]; } while(K[i]>1000000000);
  }
  
  for(k=0;k<T;k++)
  {
    count=1;
    j=1;
    while(j<=N[k])
    {
      sum=0;
      for(i=j;i<=N[k];i++)
      {
        sum+=i;
        if(sum%K[k]==0) count++;
      }
     j++;
    }
    cout<<count%1000000007<<endl;
  }
  return 0;
}