#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define loop(j,i,n) for(int j=i; j<n; j++)
#define loopk(j,i,n,k) for(int j=i; j<n; j+=k)
#define repn(i,j) for(int i=j; i>=0;i--)
#define loopn(i,j,n) for(int i=j; i>=n; i--)
#define loopnk(i,j,n,k) for(int i=j; i>=n; i-=k)

#define lim 10001
typedef long long int ll;
typedef unsigned long long ull;

using namespace std;
int main()
{
	char s[50005];
	int t[50005];
	t[0]=-1;t[1]=0;
	
	char w[50005];
	int n,z,xx,pos,d;
	int testcases;
	scanf("%d", &testcases);
	while(testcases--){

		int sl;
		scanf("%d", &sl);
		scanf("%s", s);
		int queries;
		scanf("%d", &queries);
		while(queries--){
			
			int m, n;
			scanf("%d %d", &m, &n);
			z=0;
			rep(i, n) w[i] = s[m+i];
			//loop(i, m, m+n) w[i] = s[m+i];
			w[n] = '\0';
			//printf("%s\n", w);
			int count = 0;
			
			if(n==1){
				rep(i, sl) if(s[i] == w[0]) count++;
				printf("%d\n", count);
				continue;
			}
			
			pos=2,d=0;
			while(pos<n){
				if(w[pos-1]==w[d]){t[pos++]=++d;  }
				else if(d>0) d=t[d];
				else t[pos++]=0;
			}

			
			pos=0;
			z=0;
			int ix=0;
			while(ix<sl){
				xx=z+pos; 
				if(s[ix]==w[pos]){
					pos++;
					if(pos==n){
						//printf("%d\n",z);
						count++;
						z = z + (pos - t[pos-1] - 1);
						if(pos)pos=t[pos-1];
						}
					}
				else{
				   z = z + (pos - t[pos]);
				   if(pos)pos=t[pos];
				   }
				if(xx!=(z+pos)) ix++;
			}
			printf("%d\n", count);
		}
	 
	} 
    return 0;  
}
