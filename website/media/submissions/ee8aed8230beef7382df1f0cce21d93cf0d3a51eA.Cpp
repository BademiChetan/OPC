#include<cstdio>
#include<iostream>
using namspace std;
int main()
{
	int tc,n,a,i,j,res=0;
	//scanf("%d",&tc);
cin>>tc;
	for(i=0;i<tc;i++)
	{
		res=0;
		//scanf("%d",&n);	
cin>>n;
		for(j=0;j<n;j++)
		{
	//		scanf("%d",&a);
cin>>a;
			res+=a;
		}
		n--;
		res=res-((n*(n+1))/2);
		if(res%2)
			printf("WIN\n");
		else
			printf("LOSE\n");
	}
	return 1;
}
