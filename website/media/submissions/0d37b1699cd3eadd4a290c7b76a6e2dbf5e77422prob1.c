#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long int getvalue(long int a,long int b,long int c);
main()
{

long int t,i,v;
long int x,y;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
scanf("%ld",&t);
for(i=0;i<t;i++)
	{
	scanf("%ld ",&x);
	scanf("%ld \n",&y);
	v=getvalue(x,y,x);
	printf("%ld \n",v);
	}

return 0;
}

long int getvalue(long int i,long int j,long int val)
{
long int res=1;
int k;
long int rem,res1,r,s,t;
rem=1;
for(k=0;res>=rem;k++)
{
res=j/pow(2,k);
rem=pow(2,k);
printf("---- %ld %ld %d ----\n",res,rem,k);
}


res1=j%(int)pow(2,k-1);
if(j!=0)
{
r=(long int)pow(2,k-1);
s=(long int)i/r;
t=(long int)pow(-1,s);
val=val+t*r;
//printf("%d %ld %ld %ld %ld \n",k-2,r,s,t,val);
//val=val+(long int)(pow(-1,(i/pow(2,k)))*pow(2,k));
}
if(res1==0)
return val;
else
getvalue(i,res,val);


}
