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
int W[20] , V[20], F[20];
int dp[11][100000];
pair<int,int> yash;
int calculate(int i,int w,int qtyparam){
  if(dp[i][w]!=-1){
    return dp[i][w];
  }
  else{
    int tmp1,tmp2,tmp3;
    tmp2=-1;
    tmp1=calculate(i-1,w,F[i-1]);
    if(qtyparam>1){
      if(w-W[i]>=0)
	tmp2=calculate(i,w-W[i],qtyparam-1)+V[i];
    }
    if(qtyparam==1){
      if(w-W[i]>=0)
	tmp2=calculate(i-1,w-W[i],F[i-1])+V[i];
    }
    dp[i][w]=max(tmp1,tmp2);
    return dp[i][w];
  }
}
int main()
{
  int tc;
  scanf("%d",&tc);
  int maxW ;
  int yash1;
  int i,j;
  int items;
  for(yash1=0 ; yash1<tc ; yash1++)
  {
    scanf("%d%d",&items, &maxW);
    for(j=0 ; j<items ; j++)
    {
      scanf("%d%d%d",&W[j+1], &V[j+1], &F[j+1]);
    }  /*
    for(i=0;i<=items;i++){
      for(j=0;j<=maxW;j++){
	dp[i][j]=-1;
      }
    }	  */
    //   dp.clear();
    for(i=0;i<=maxW;i++){
      //yash.first=0;
      //yash.second=i;
      dp[0][i]=0;
    }
    for(i=0;i<=items;i++){
      // yash.first=i;
      // yash.second=0;
      dp[i][0]=0;
    }
    //yash.first=items;
    //yash.second=maxW;
    printf("%d\n",calculate(items,maxW,F[items]));
  }
  return 0;
}
