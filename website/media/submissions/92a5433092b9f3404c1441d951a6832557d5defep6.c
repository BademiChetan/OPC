#include<stdio.h>
#include<string.h>
char T[1000000],P[1000005];
int overlap[1000005];
int main()
{
long long i,j,m,n,t_case,Q,st,len,xx,t,count=0;
j=0;

scanf("%lld",&t_case);

while(t_case--)
{
scanf("%lld",&m);
scanf("%s",T);
scanf("%lld",&Q);
while(Q--)
{

scanf("%lld %lld",&st,&len); 
for(xx=st,t=0;t<len;t++)
{
P[t]=T[xx++];
}
P[t]='\0';

overlap[0]=-1;
for(i=0;P[i]!='\0';i++)
{
overlap[i+1]=overlap[i]+1;
while(overlap[i+1]>0&&P[i]!=P[overlap[i+1]-1])
overlap[i+1]=overlap[overlap[i+1]-1]+1;
}
 
n=len;
count=0;
if(m>n)
{
j=0;
	for(i=0;i<m;i++)
	{
		for(;;)
		{
 
			if(T[i]==P[j])
			{
				j++;
 
				if(j==n)
				{
					count++;
					j=overlap[j];
				}
			break;
 
			}
			else if(j==0)
			{
				break;
			}
			else
			{
				j=overlap[j];
			}
		}
	}
}


printf("\n%lld",count);
}//while Q 
}//while T
return 0;
}
 
