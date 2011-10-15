# define MAX 1000

# include <iostream>

using namespace std;

unsigned long int pow (const unsigned long int& x, const unsigned long int& y)
{
    unsigned long int r = x;
    for (unsigned long int i = y; i > 1; --i )
    {
        r *= x;
    }
    return r;
}

int main ()
{
	unsigned short int n;
	unsigned long int N[MAX], K[MAX];
	cin >> n;
	for (unsigned short int i = 0; i < n; ++i)
	{
		cin >> N[i] >> K[i];
	}
	for (unsigned short int i = 0; i < n; ++i)
	{
	    unsigned long int s = 2;
	    bool flag = true;
	    for (unsigned long int j = 2; flag; ++j)
	    {
	        if ( ( pow (2,j) % K[i] ) == 2 )
	        {
	            flag = false;
	            s = j-1;
	        }
	    }
	    if ( N[i] % s )
	    {
	        cout << ( pow ( 2, ( pow ( 2, ( N[i] % s ) % K[i] ) ) ) ) << endl;
	    }
	    else
	    {
	        cout << pow ( 2, ( pow ( 2, s ) % K[i] ) ) << endl;
	    }
	}
    return 0;
}
