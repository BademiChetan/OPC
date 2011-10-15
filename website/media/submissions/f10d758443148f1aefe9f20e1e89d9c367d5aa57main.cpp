#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t,sum[100],n,i,k,s;
    cin>>t;
    while(t--)
    {s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {scanf("%d",&sum[i]);
    s=s+sum[i];
    }

      k=n*(n-1)/2;
      s=s-k;
      if(s%2==0)
      printf("LOSE\n");
      else
      printf("WIN\n");
    }
    return 0;
}
