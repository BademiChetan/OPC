#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
int i,j,k,a,b,t,temp,T,N[50],n[50][50];

clrscr();

printf("\n Enter the first line and press enter:\n");
scanf("%d",&T);
//   input values of all the test cases...
for(i=0;i<T;i++)
{
printf("\n Enter the line containing the value of N:\n");
scanf("%d",N[i]);
printf("\n Enter the values of integer set separated by spaces: \n");
for(j=0;j<N[i];j++)
{
	scanf("%d",&n[i][j]);
}
}

t=0;
for(i=0;i<T;i++)	    // for every test case
{
j=N[i];
j-=1;
while(N[i]>1)
{
	t=1;
	a=n[i][j];
	j-=1;
	b=n[i][j];
	N[i]--;
	n[i][j]=a-b+t;
}
}

if((N[0]%2)==0)
{
	printf("LOSE, i.e. Prashant Wins");
}
else
{
	printf("WIN, i.e. Srivatsan Wins");
}

}



