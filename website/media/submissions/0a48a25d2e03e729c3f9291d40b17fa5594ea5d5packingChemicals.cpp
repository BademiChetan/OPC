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
map<pair<int, int> , int> dp;
map<pair<int, int> , int>::iterator it;
int W[20] , V[20], F[20];
pair<int,int> yash;
int calculate(pair<int,int> tmp,int qtyparam){
  it=dp.find(tmp);
  if(tmp.first <= 0){
  return 0;
  }
  else if(it!=dp.end()){
    return dp[tmp];
  }
  else{
    int tmp1,tmp2,tmp3;
    tmp2=-1;
    yash.first=tmp.first-1;
    yash.second=tmp.second;
    yash.second=max(tmp.second,0);
    tmp1=calculate(yash,F[tmp.first-1] );
    if(qtyparam>1&&tmp.second-W[tmp.first]>=0){
      yash.first=tmp.first;
      yash.second=tmp.second-W[tmp.first];
      tmp2=calculate(yash,qtyparam-1)+V[tmp.first];
    }
    if(qtyparam==1&&tmp.second-W[tmp.first]>=0 && tmp.first > 1){
      yash.first=tmp.first-1;
      yash.second=tmp.second-W[tmp.first];
      tmp2=calculate(yash,F[tmp.first-1])+V[tmp.first];
    }
    dp[tmp]=max(tmp1,tmp2);
    return dp[tmp];
  }
}
int main()
{
  int tc;
  scanf("%d",&tc);
  int maxW ;
  int yash1;
  int i,j;
  int items , temp;
  int lcm;
  for(yash1=0 ; yash1<tc ; yash1++)
  {
    scanf("%d%d",&items, &maxW);
    for(j=0 ; j<items ; j++)
    {
      scanf("%d%d%d",&W[j+1], &V[j+1], &F[j+1]);
    }
    for( i=1 ; i<=items ; i++)
    {
      for(j=1 ; j<items ; j++)
      {
	if(V[j]*1.0/W[j] < V[j+1]*1.0/W[j+1])
	{
		temp = W[j];
		W[j] = W[j+1];
		W[j+1] = temp;
		temp = V[j] ; 
		V[j] = V[j+1];
		V[j+1] = temp;
		temp = F[j] ; 
		F[j] = F[j+1];
		F[j+1] = temp;
	}

      }
    }
    /*for(i=0;i<=items;i++){
      for(j=0;j<=maxW;j++){
      dp[i][j]=-1;
      }
      }*/	
    dp.clear();
   /* for(i=0;i<=maxW;i++){
      yash.first=0;
      yash.second=i;
      dp[yash]=0;
    }*/

    int g = __gcd(W[1], W[2]);

    for(i=3 ; i<= items ; i++)
      g = __gcd(g, W[i]);
    g = __gcd(g, maxW);
    for( i=1 ; i<= items ; i++)
      W[i] /= g;
    maxW /= g;
    for(i=0;i<=items;i++){
      yash.first=i;
      yash.second=0;
      dp[yash]=0;
    }
    yash.first=items;
    yash.second=maxW;
    printf("%d\n",calculate(yash,F[items]));
  }
  return 0;
}
