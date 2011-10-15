#include<stdio.h>
int main()
{
	long int t,x,y,i,temp,a[10002];
	scanf("%ld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%ld%ld",&x,&y);
		if(x<y)
		{
			temp=x;
			x=y;
			y=temp;
		}
		if(y==0)
		{
			a[i]=x;
		}
		else if(((x-y)==1)&&((x+y-1)%4==0))
		{
			a[i]=1;
		}
		else if(x==y)
		{
			a[i]=0;
		}
		else if((x==2)&&(y==1))
		{
			a[i]=3;
		}
		else if((x+1)%4==0)
		{
			a[i]=x-y;
		}
		else if((x+1)%4==1)
		{
			a[i]=x+y;
		}
		else if((x+1)%4==2)
		{
			if(y%2==0)
			{
				a[i]=x+y;
			}
			else
			{
				a[i]=x+y-2;
			}
		}
		else if((x+1)%4==3)
		{
			if(y%2==0)
			{
				a[i]=x-y;
			}
			else
			{
				a[i]=x-y+2;
			}
		}
	}
	for(i=0;i<t;i++)
	{
		printf("%ld\n",a[i]);
	}
	return 0;
}

