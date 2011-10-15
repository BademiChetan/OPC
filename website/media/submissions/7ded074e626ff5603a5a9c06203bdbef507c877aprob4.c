#include<stdio.h>
void arrange(int a[][3],int n)
{	int i,j,t1,t2,t3;
	for(i=0;i<n;i++)
	for(j=0;j<n-i-1;j++)
	{	if(a[j][1]>a[j+1][1])
		{	t1=a[j][0];a[j][0]=a[j+1][0];a[j+1][0]=t1;
			t2=a[j][1];a[j][1]=a[j+1][1];a[j+1][1]=t2;
			t3=a[j][2];a[j][2]=a[j+1][2];a[j+1][2]=t3;
		}
	}
}
		
int main()
{	int t,n,a[10][3],p,i,j,res;
	scanf("%d",&t);
	while(t--)
	{	scanf("%d%d",&n,&p);
		for(i=0;i<n;i++)
		for(j=0;j<3;j++)
		scanf("%d",&a[i][j]);
		arrange(a,n);res=0;
		for(i=n-1;i>=0;i--)
		{	if(a[i][2]*a[i][0]<=p)
			{p-=a[i][2]*a[i][0];res+=a[i][1]*a[i][2];}
			else if(a[i][0]<=p){p-=(p/a[i][0])*a[i][0];res+=(p/a[i][0])*a[i][1];}
			if(p==0)break;
		}
		printf("%d\n",res);
	}
	return 0;
}
		
