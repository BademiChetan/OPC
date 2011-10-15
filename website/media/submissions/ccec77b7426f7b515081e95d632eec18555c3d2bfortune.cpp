# include <cstdio>
# include <cstdlib>
# include <vector>
# include <set>
# include <map>
# include <deque>
# include <algorithm>
# include <cctype>
# include <iostream>
# include <cstring>
# include <fstream>
#include <iomanip>

/*
# include <unistd.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>
*/

# define FR(i, n)           for( int i = 0; i < n; i++)
# define FRin(i, m, n)     for( int i = m; i < n; i++)
# define FRrev(i, n)         for( int i = n; i >= 0; i-- )
# define PF    printf
# define SFd(x)    scanf("%d",&x)
# define SFl(x) 	scanf("%d", &llx)
# define PB    push_back

using namespace std;

//To get a^x(mod b)
long long getPowModulo(long long base, long long exp, long long modulo)
{
    if(exp == 0)
    return 1;
    
    long long  toMult = base % modulo;
    long long modAns = toMult;
    vector<int> binaryExp;
    
    while(exp != 0)
    {
        binaryExp.push_back(exp%2);
        exp /= 2;
    }
    
    for(int i = binaryExp.size()-2; i >=0 ; i--)
    {
        modAns = (modAns * modAns) % modulo;
        if(binaryExp[i])
        {
            modAns = (modAns * toMult) % modulo;
        }
    }    
    
    return modAns;
}//end of a^x(mod b) function



int main()
{
	int t;
	SFd(t);
	
	
	while ( t-- )
	{
		int ref = 0;
		int n;
		int k;
		SFd(n);
		SFd(k);
		
		FRin( i, 1, 64 )
		{
			if ( getPowModulo(2,i,k) == (long long)1 )
			{
				ref = i;
				break;
			}
		}
		
		long long int rem;
		
		rem = getPowModulo(2,n,ref);
		
		long long ans = (( (long long)1 << rem )%k);
		
		PF("%lld\n", ans);
	}
	return 0;
}

