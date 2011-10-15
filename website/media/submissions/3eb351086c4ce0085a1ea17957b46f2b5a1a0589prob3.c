#include<stdio.h>
main()
{
int testcase,i;
scanf("%d",&testcase);
long int j,nofdays,kodd,ans;
for(i=0;i<testcase;i++)
{
	ans=2;	
	scanf("%ld",&nofdays);
	scanf("%ld",&kodd);
	for(j=0;j<nofdays;j++)
	ans=ans*ans;
	printf("%ld",ans%kodd);
}
}
