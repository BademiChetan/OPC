#include<iostream.h>
#include<math.h>
int main()
{
	int i,j;
	long int x,y;
	int test,length;
	cin>>test;
	while(test--)
	{
	  cin>>x;
	  cin>>y;
	  {
	   for(i=0;i<=x;i++)
	   {
		for(j=0;j<=y;j++)
		{
			length=abs(j-i);
		}
	   }
	  }
	  cout<<length;
	}
return 0;
}