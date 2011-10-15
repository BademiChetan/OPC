#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,t,* a,i,s;
scanf("%d",&t);
while(t)
{
scanf("%d",&n);
a = (int *)malloc(n*sizeof(int));
for(i=0;i<n;i++)
{
      scanf("%d",a+i);               
}
i=1;
s = a[0];
while(i<n)
{
s += a[i] -i;
i++;          
}
if(s%2)
       printf("WIN\n");
else
        printf("LOSE\n");
        free(a);
t--;
}
	return 0;
}
