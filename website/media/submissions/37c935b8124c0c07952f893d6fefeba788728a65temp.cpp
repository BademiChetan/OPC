#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cassert>
#include<ctime>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>

#define PB push_back
#define M 100
#define N 100
#define LL long long



using namespace std;

int pow2gtnum(int num)
{
	int i=0,j=1;
	for(;j<=num;++i)
	{
		j*=2;
	}
	return j;
}

int find_num(int row,int col)
{
	
	int arr[2][2],ans;
	arr[0][0]=0;
	arr[0][1]=1;
	arr[1][0]=1;
	arr[1][1]=0;
	if(row<=1 && col <=1)
	return arr[row][col];
	//enum quadrant {FIRST,SECOND,THIRD,FOURTH};
	int pw=pow2gtnum(max(row,col));
	//quadrant quad;

	/*if(row<pw/2 && col < pw/2)
	{
		ans=find_num(row,col);	
		printf("row col %d %d return %d \n",row,col,ans);
		return  ans;
	}*/
	
	if(row<pw/2 && col >= pw/2)
	{
		ans=pw/2+find_num(row,col-pw/2);
		return ans;
	}
	
	if(row >= pw/2 && col < pw/2)
	{
		ans= pw/2+find_num(row-pw/2,col);
		//printf("row col %d %d return %d \n",row,col,ans);
		return  ans;
	}
	
	if(row >= pw/2 && col >= pw/2)
	{
		ans= find_num(row-pw/2,col-pw/2);
		//printf("row col %d %d return %d \n",row,col,ans);
		return  ans;
	}
}


int main()
{
	int tc,row,col;
	scanf("%d",&tc);
	
	while(tc--)
	{
		scanf("%d %d",&row,&col);
		printf("%d\n",find_num(row,col));
	}
	return 0;
}
