#include<iostream>

using namespace std;

int main()
{
	int t,n,sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=1;
		int turn=1;
		while(n--)
		{
			int temp;
			cin>>temp; sum+=temp-turn;
			turn++;
		}
		(sum%2)?(cout<<"WIN\n"):(cout<<"LOSE\n");
	}
	return 0;
}
