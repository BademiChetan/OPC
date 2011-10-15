#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
 int t;
 scanf("%d",&t);
 int a[100][2];
 int i,j;
 for(i=0;i<t;i++)
 {
  for(j=0;j<2;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 int m,q;
 for(i=1;i<t;i++)
 {
  j=0;
  m=a[i][j]%a[i][j+1];
  q=2;
  for(int k=1;k<=m;k++)
  {
   q=pow(q,2);
   printf("\n");
   printf("%d",q);
  }
 }
 return 0;
}
