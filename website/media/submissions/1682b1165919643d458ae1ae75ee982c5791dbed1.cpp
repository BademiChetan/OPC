#include<vector>
#include<string>
#include<iostream>
#include<math.h>
using namespace std;

int sol( int i,int j)
{
	if( i == 0 && j == 0 )
	{
		return 0;
	}
	if( i == 0 )
	{
		return j;
	}
	if( i != 0 )
	{
		int ii = log(float(i) + 0.5 )/log(2);
		ii = pow( 2, ii );
		int jj = log(float(j) + 0.5 )/log(2);
		jj = pow( 2, jj );
		
		int temp = j%(2*ii);
		if( temp < ii )
		{
			return jj+ii + sol(i - ii, j - jj );
		}
		else
		{
			return jj - ii + sol( i - ii, j  -jj );
		}
	}
}

int main()
{
	int t;
	cin>>t;
	for( int d = 0; d < t;d ++)
	{
	int r,c;
	cin>>r>>c;	
	cout<<sol(r,c)<<endl;
	}
	return 0;
}


