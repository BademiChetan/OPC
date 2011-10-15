#include<stdio.h>
#include<stdlib.h>
int main()
{
int *num;
char **str;
int n,a,b,c,i;
int t=1;
scanf("%d",&n);
num=malloc(sizeof(int)*n);
str=malloc(sizeof(char)*n*6);
for(i=0;i<n;i++)
{
scanf("%d",&a);
t=1;
do
{
scanf("%d %d",&b,&c);
if(((b+c)-t)%2==0)
str[i]="LOSE";
else
str[i]="WIN";
t++;
a=a-1;
}while(a>1);
}
for(i=0;i<n;i++)
printf("%s\n",str[i]);
return 0;
}
