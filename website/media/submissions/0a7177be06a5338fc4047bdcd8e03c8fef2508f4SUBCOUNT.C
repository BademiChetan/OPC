#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
void subcnt(int,int);
int main()
{
	int i,t;
	int*a,*b;
	clrscr();
	printf("enter the number of test cases:");
	scanf("%d",&t);
	if(t<1||t>1000)
	{
		printf("invalid number of test cases reexecute\n\n");
		return 1;
	}
	a=(int *)malloc(sizeof(int)*t);
	b=(int *)malloc(sizeof(int)*t);
	printf("\nenter N and k \n");
	for(i=0;i<t;i++)
	{
		 scanf("%d%d",&a[i],&b[i]);
	}
	for(i=0;i<t;i++)
	{
		subcnt(a[i],b[i]);
	}
	getch();
	return 0;
}
void subcnt(int n,int k)
{
   int sum,cnt=0,i,j,r,l;
   for(i=0;i<=pow(2,n);i++)
   {
	sum=0;
	j=i;
	l=1;

	while(j!=0)
	{
		r=j%2;
		j=j/2;
		if(r==1)
		sum+=l;
		l=l++;
	}
	if(sum%k==0)
	cnt++;
   }
   printf("\n number of subset sum which is divisible by k is=%d",cnt);
}


