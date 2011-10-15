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
	long N=1000001;
	scanf("%d",&t);
	TSTCASE(t)
	{
		long x,y;
		scanf("%ld %ld",&x,&y);
		if(x<=y)printf("%ld\n",y-x);
		else printf("%ld\n",y+1);
	}
	return 0;
}
