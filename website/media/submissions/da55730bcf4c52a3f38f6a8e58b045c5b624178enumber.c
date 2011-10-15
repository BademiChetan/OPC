#include<stdio.h>
#include<stdlib.h>
int main()
{
int *num;
char **str;
int *choice;
int n,a,j,i;
scanf("%d",&n);
num=malloc(sizeof(int)*n);
str=malloc(sizeof(char)*n*6);
for(i=0;i<n;i++)
{
	scanf("%d",&a);
	choice=malloc(sizeof(int)*a);
	for(j=0;j<a;j++)
		scanf("%d",&choice[j]);
	for(j=1;j<=a-1;j++)
		choice[j]=choice[j-1]+choice[j]-j;
	if(choice[j-1]%2==0)
		str[i]="LOSE";
	else
		str[i]="WIN";
}
for(i=0;i<n;i++)
	printf("%s\n",str[i]);
return 0;
}
