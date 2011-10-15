#include<stdio.h>
#include<math.h>
int main()
{
	int i,j;
	long int x,y,N;
	int test,length;
	scanf("%d",&test);
	while(test--)
	{
      //scanf("%d",&N);
	  scanf("%d",&x);
	  scanf("%d",&y);
	  //while(N>x && N>y)
	  {
	   for(i=0;i<=x;i++)
	   {
		for(j=0;j<=y;j++)
		{
			length=abs(j-i);
		}
	   }
	  }
	  printf("%d\n",length);
	}
	 return 0;
}