# include <stdio.h>

void main()
{
unsigned int n,i,k,t,j;unsigned int doub;
printf("enter test cases :");
scanf("%u",&t);
for(j=1;j<=t;j++)
{
doub=2;
printf("\nenter n : ");
scanf("%u",&n);
printf("enter k :");
scanf("%u",&k);

for(i=1;i<=n%k;i++)
{

doub=doub*doub;

}


printf("answer = %u",doub);
}

}


