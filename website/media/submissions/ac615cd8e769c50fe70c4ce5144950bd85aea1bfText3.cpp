#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int T,i,*p,N,K;
	cin>>T;
	p=new int[T];
	for(i=0;i<T;i++)
	{
	    cin>>N;
		cin>>K;
		p[i]=static_cast<int>(pow(2.0,2.0*N))%K;
    }
	for(i=0;i<T;i++)
	{
	    cout<<p[i]<<endl;
	}
	delete [] p;
	return 0;
}

