#include<stdio.h>
int main()
{
int t,m,pm=0,tn;
int a[10];
char rp[100];
 scanf("%d",&t);
 for(int i=0;i<t;i++)
 {
  int k=0;
  scanf("%d",&m);
  for(int j=0;j<m;j++)
  {
	scanf("%d",&a[j]);
  }
  k=a[0]+a[1]-1;
  tn=2;
  for(int l=2;l<=m;l++)
  {
	k=k+a[l]-tn;
	tn++;
  }
  int ans;
  ans=k%2;
  if(ans==1)
  {
	 rp[pm]='w';
	 pm++;
  }
  else
  {
	rp[pm]='l';
	pm++;
  }
 }
 for(int y=0;y<pm;y++)
 {
  if(rp[y]=='w')
  {
	printf("LOSE");
	printf("\n");
  }
  else
  printf("WIN");
  printf("\n");
  }
return 0;
}
