#include<stdio.h>
main()
{
int t,i;
scanf("%d",&t);
for(i=0;i<t;i++)
{
int n,j,r;
scanf("%d",&n);
int g[n];
for(j=0;j<n;j++)
{
	scanf("%d",&g[j]);
}
int u=0,v=0;
for(j=0;j<n-1;j++)
{ 	if(j/2*2 != j)
	{
	u++;
	g[j+1]=g[j]+g[j+1]-u;
	}
	if(j/2*2 == j)
        {
        v++;
        g[j+1]=g[j]+g[j+1]-v;
        }
}
if(g[n-1]/2*2==g[n-1]) printf("LOOSE");
else printf("WIN");
}
return 0;
}
