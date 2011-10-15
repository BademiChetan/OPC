#include<stdio.h>
#include<string.h>
char T[50005],P[50005];
int overlap[50005];
int main()
{
long int i,j,m,n,Q,st,len,xx,t,count=0;
int t_case,flag;
j=0;

scanf("%d",&t_case);

while(t_case--)
{
scanf("%ld",&m);
scanf("%s",T);
scanf("%ld",&Q);
while(Q--)
{

scanf("%ld %ld",&st,&len); 
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
j=0;
	for(i=0;i<m;i++)
	{
 		flag=1;
		while(flag)
		{

			if(T[i]==P[j])
			{
				j++;
 
				if(j==n)
				{
					count++;
					j=overlap[j];
				}
			flag=0;
 
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


printf("\n%ld",count);
}//while Q 
}//while T
return 0;
}
 
