#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int t,n,sum,tmp;
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		for(int i=0;i<n;i++) { cin>>tmp; sum+=tmp; }
		sum -= ((n-1)*n/2);
		if(sum%2)
			cout<<"WIN"<<endl;
		else
			cout<<"LOSE"<<endl;
	}
	return 0;
}

