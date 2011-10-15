#include<stdio.h>
int max(int w,int e)
{
if(w>e) return w;
else return e;
}

main()
{
int t,i;
scanf("%d",&t);
for(i=0;i<t;i++)
{       long x,y,p,q,h,k,a;
	scanf("%ld %ld",&x,&y);
	long X[x+1][y+1];
	for(p=0;p<=y;p++)
	for(q=0;q<=x;q++)
	{	X[0][0]=0;int w,e;
		for(h=0;;h++)
		{
		{w=0;
		for(a=0;a<q;a++)
        	{ if(X[a][p]!=h) w++;
		}}
		{e=0;
                for(a=0;a<p;a++)
                { if(X[q][a]!=h) e++;
                }}

               if(e+w==p+q) break;}
	
		X[q][p]=h;
	}
	printf("%ld",X[x][y]);
}
}

