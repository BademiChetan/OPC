#include<stdio.h>
#include<algorithm>
using namespace std;


int test,t,a;
int ans;
int l[5000];
int m[5000];
int n[5000];
int p;

int memo[90][90][1100];

int dp(int w, int h,int c)
{
  if(w<0) w=0;
  if(h<0) h=0;
  if(memo[w][h][c]!=-1) return memo[w][h][c];
  
  if(w==0 && h==0) return 0;
  
  if(c>p) return 1500000;
  else {
    memo[w][h][c] = min(dp(w-l[c],h-m[c],c+1) + n[c], dp(w,h,c+1));
    return memo[w][h][c];
   }
}        
    
    




int main()
{
 
 scanf("%d",&test);
 for(int i=1;i<=test;i++){
  memset(memo,-1,sizeof(memo));       
  scanf("%d %d",&t,&a);
  scanf("%d",&p);
  for(int j=1;j<=p;j++)
   scanf("%d %d %d",&l[j],&m[j],&n[j]);       
   ans=dp(t,a,1);       
   printf("%d\n",ans);                
 }  
 
}
