#include<stdio.h>
main()
{
 int t,n[100],i=0,j=0,a[100][100],temp;
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
  scanf("%d",&n[i]);
  for(j=0;j<n[i];j++)
	scanf("%d",&a[i][j]);
 }
 for(i=0;i<t;i++)
 {
  for(j=1;j<=n[i];j++)
  {
  if(j==n[i])
   {
	if(a[i][j]%2==0)
	{
	 printf("WIN");
	}
	else
	{
	 printf("LOSE");
	}
   }
   else
   {
	temp=a[i][j]+a[i][j+1]-j;
	a[i][j+1]=temp;
   }
 }
printf("\n");
}
return 0;
}