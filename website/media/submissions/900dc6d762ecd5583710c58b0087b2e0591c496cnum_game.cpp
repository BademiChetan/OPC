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
# define SFd(x)    scanf("%d",& x )
# define PB    push_back

using namespace std;

int main()
{
	int t;
	SFd(t);
	while ( t-- )
	{
		int n;
		SFd(n);
		bool ansodd = true;
		int temp = (n-1)%4;
		if ( temp == 1 || temp == 2)
		ansodd = true;
		else
		ansodd = false;
		
		FR(i, n)
		{
			int currnum;
			SFd(currnum);
			if ( (currnum & 1))
			ansodd = (!(ansodd));
		}
		if ( ansodd )
		PF("WIN\n");
		else
		PF("LOSE\n");
	}
	return 0;
}

