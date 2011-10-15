      #include<stdio.h>
      int main(void)
      {
      int t,i,j,temp,no,dig,n,k,l,dig1;
      int a[100000000],ans[100000000];
      scanf("%d",&t);
      while(t--)
      {
	scanf("%d%d",&n,&k);
      	a[0]=2;dig=1;temp=0,dig1=1;
      	for(i=1;i<(n%k)+1;i++)
      	{
		for(j=0;j<dig+1;j++)
		{
			ans[j]=0;
		}
		for(l=0;l<dig;l++)
		{
			dig1=dig;
      			for(j=0;j<dig;j++)
      			{
      				ans[j+l]=ans[j+l]+a[j]*a[l]+temp;
      				temp=ans[j+l]/10;
      				ans[j+l]=ans[j+l]%10;
			}
			dig1=j+l;
      			while(temp>0)
      			{

      				ans[dig1]=temp%10;
      				dig1++;
      				temp/=10;
      			}
		}
		for(j=0;j<dig1;j++)
		{
			a[j]=ans[j];
		}
		dig=dig1;
	}
      	for(i=dig1-1;i>=0;i--)
      	{
      		printf("%d",a[i]);
      	}
      	printf("\n");
      }
      return 0;
     }

