#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long int getvalue(long int a,long int b,long int c);
main()
{

long int t,i,v;
long int x,y;
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
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
long int res=2;
int k,g;
long int rem,res1,r,s,t;
rem=0;
if(j==0)
return val;
for(k=0;;k++)
{
res=j/(long int)pow(2,k);
//rem=pow(2,k);

if(res<=1)
break;
}

g=k;

res1=j%(int)pow(2,g);
if(j!=0)
{
r=(long int)pow(2,g);
s=(long int)i/r;
t=(long int)pow(-1,s);
val=val+t*r;

}
if(res1==0)
return val;
else
getvalue(i,res,val);


}
