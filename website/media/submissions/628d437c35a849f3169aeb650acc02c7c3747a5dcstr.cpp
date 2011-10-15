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

#define MAXBUFF 1000000
char buffer[MAXBUFF]; 
int bpos;
inline void Init() { bpos = MAXBUFF; }
inline char read_char() {
	    if( bpos == MAXBUFF ) { bpos = 0; fread( buffer, 1, MAXBUFF, stdin ); }
        return buffer[ bpos++ ];
}

inline int read_int() {
        char c; int ret;

        while( !isdigit( c = read_char() ) );
        ret = c - '0';

        while(  isdigit( c = read_char() ) )
	        ret = ( ret * 10 + c - '0' );

        return ret;
}

int main()
{
	char s[50005];
	int t[50005];
	t[0]=-1;t[1]=0;
	
	char w[50005];
	int n,z,xx,pos,d;
	int testcases;
	//scanf("%d", &testcases);
	testcases = read_int();
	while(testcases--){

		int sl;
		sl = read_int();
		rep(i, sl) s[i] = read_char();
		s[sl] = '\0';
		int queries;
		queries = read_int();
		while(queries--){
			
			int m, n;
			m = read_int();
			n = read_int();
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
