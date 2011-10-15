#include<stdio.h>
#include<math.h>
int main()
{

	int t;
	int a,b,i;
	int ans;
	int arr[100];
	scanf("%d",&t);

	if((t>0)&&(t<1001))
	{
		for(i=0;i<t;i++)
		{
		  scanf("%d",&a);
		  if(a>0)
		    {
		      scanf("%d",&b);
			  if(b<(pow(10,9))&&((b%2)!=0))
			    {
				 ans=(int)(pow(2,pow(2,a)))%b;
				 arr[i]=ans;
			    }
			   else return 0;
		     } else return 0;
		 
	     }
	}else return 0;

     for(i=0;i<t;i++)
		 printf("%d\n",arr[i]);
	return 0;

}