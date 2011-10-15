#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#define FOR(i,m,n) for(int i=(m);i<(n);i++)
#define TSTCASE(n) int T=(n); while(T--) 
#define SWAP(a,b,t) t=a; a=b; b=t;
          
using namespace std;
        
int main()
{
int t;
scanf("%d",&t);
TSTCASE(t)
{
	int n;
	scanf("%d",&n);
	int a[n];
	int k=0;
	FOR(i,0,n)
	{
		scanf("%d",&(a[i]));
		if(a[i]%2==1)k++;
	}
	if(k>=n-k)printf("LOSE\n");
	else printf("WIN\n");
}
return 0;
}
