#include<stdio.h>
int main()
{
int T,M,i,j,N;
int total=0;
int a[100];
scanf("%d",&T);
if(T>100)
{
printf("constraint\n");
return 0;
}
for(i=0;i<T;i++)
{
 scanf("%d",&N);
 if(N>100)
 {
 printf("constraint\n");
 return 0;
 }
 for(j=1;j<=N;j++)
  scanf("%d",&a[j]);
  if(a[j]>100)
  {
  printf("constraint\n");
  return 0;
  }
  for(j=1;j<=N;j++)
  total=a[j]+total;
 M=N*(N-1)/2;
 if(((total-M)%2)==0)
  {
   printf("LOSE\n");
  }
  else
   printf("WIN\n");
   total=0;
 }
 return 0;
 }

