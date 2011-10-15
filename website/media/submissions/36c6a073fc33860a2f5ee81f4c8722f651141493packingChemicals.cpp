#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<stack>
#include<queue>
using namespace std;
int dp[12][10000000];
int W[20] , V[20], F[20];
int calculate(int i,int w,int qtyparam){
  if(dp[i][w]!=-1){
    return dp[i][w];
  }
  else{
    int tmp1,tmp2,tmp3;
    tmp2=-1;
    tmp1=calculate(i-1,w,F[i-1] );
    if(qtyparam>1)
      tmp2=calculate(i,w-W[i],qtyparam-1)+V[i];
    if(qtyparam==1)
      tmp2=calculate(i-1,w-W[i],F[i-1])+V[i];
    dp[i][w]=max(tmp1,tmp2);
    return dp[i][w];
  }
}
int main()
{
  int tc;
  scanf("%d",&tc);
  int maxW ;
  int yash;
  int i,j;
  int items;
  for(yash=0 ; yash<tc ; yash++)
  {
    scanf("%d%d",&items, &maxW);
    for(j=0 ; j<items ; j++)
    {
      scanf("%d%d%d",&W[j+1], &V[j+1], &F[j+1]);
    }
    for(i=0;i<=items;i++){
      for(j=0;j<=maxW;j++){
	dp[i][j]=-1;
      }
    }	
    for(i=0;i<=maxW;i++){
      dp[0][i]=0;
    }
    for(i=0;i<=items;i++){
      dp[i][0]=0;
    }
    
    printf("%d\n",calculate(items,maxW,F[items]));
	
  }
  return 0;
}
