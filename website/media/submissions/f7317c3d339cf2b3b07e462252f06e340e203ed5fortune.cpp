#include<iostream>
using namespace std;

int main()
{
	int t,day,i,m,j;
	cin>>t;
	for(j=0;j<t;j++)
	{
		cin>>day>>m;
		int temp=2;
		for(i=0;i<day;i++)
			if(temp<m)
				temp*=temp;
			else
			{
				temp%=m;
				break;
			}
		for(i++;i<day;i++)		
			temp=(temp*temp)%m;
		cout<<temp<<endl;
	}
	return 0;
}
