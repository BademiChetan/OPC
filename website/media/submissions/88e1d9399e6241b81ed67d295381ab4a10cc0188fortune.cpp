#include <iostream>

using namespace std;

int main()
{
	int T;
	long int N[1000];
	long long int K[1000];

	cin>>T;
	for(int i=0;i<T;++i)
	{
		cin>>N[i]>>K[i];
	}

	for(int i=0;i<T;++i)
	{
		int tmp = N[i];
		for(int j=0;j<tmp+1;++j)
		{
			N[i] *= T;			
		}
		N[i] %= K[i];
		cout<<N[i]<<endl;
	}

	return 0;
}