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
		if(x==0)
		{
			a[i]=y;
			//printf("%ld\n",y);
		}
		else if(((x-y)==1)&&((x+y-1)%4==0))
		{
			a[i]=1;
			//printf("1\n");
		}
		else if(x==y)
		{
			a[i]=0;
			//printf("0\n");
		}
		else if((x==2)&&(y==1))
		{
			a[i]=3;
			//printf("3\n");
		}
		else if((x+1)%4==0)
		{
			a[i]=x-y;
			//printf("%ld\n",x-y);
		}
		else if((x+1)%4==1)
		{
			a[i]=x+y;
			//printf("%ld\n",x+y);
		}
		else if((x+1)%4==2)
		{
			if(y%2==0)
			{
				a[i]=x+y;
				//printf("%ld\n",x+y);
			}
			else
			{
				a[i]=x-y;
				//printf("%ld\n",x-y);
			}
		}
		else if((x+1)%4==3)
		{
			if(y%2==0)
			{
				a[i]=x-y;
				//printf("%ld\n",x-y);
			}
			else
			{
				a[i]=x-y+2;
				//printf("%ld\n",x-y+2);
			}
		}
	}
	for(i=0;i<t;i++)
	{
		printf("%ld\n",a[i]);
	}
	return 0;
}

