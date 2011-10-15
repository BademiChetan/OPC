#include"iostream"
using namespace std;
int A[8][8];
int solve(int x, int y, int pw)
{
	int blockx=x/8;
	int blocky=y/8;
	int  i=x%8;
	int  j=y%8;	
	int start;
	if(blockx>=8||blocky>=8){
		start=solve(blockx,blocky,pw*8);
	}
	else {
		start=pw*A[blockx][blocky];
	}
	int ret=start+(pw/8)*A[i][j];
	return ret;
}
int main()
{
	int i;
	for(i=0;i<8;i++){
		A[0][i]=i;
	}
	
	int V[]={1,0,3,2,5,4,7,6};
	for(i=0;i<8;i++)
		A[1][i]=V[i];

	int V1[]={2,3,0,1,6,7,4,5};
	for(i=0;i<8;i++)
		A[2][i]=V1[i];

	int V2[]={3,2,1,0,7,6,5,4};
	for(i=0;i<8;i++)
		A[3][i]=V2[i];
	int V3[]={4,5,6,7,0,1,2,3};
	for(i=0;i<8;i++)
		A[4][i]=V3[i];

	int V4[]={5,4,7,6,1,0,3,2};
	for(i=0;i<8;i++)
		A[5][i]=V4[i];

	int V5[]={6,7,4,5,2,3,0,1};
	for(i=0;i<8;i++)
		A[6][i]=V5[i];

	int V6[]={7,6,5,4,3,2,1,0};
	for(i=0;i<8;i++)
		A[7][i]=V6[i];
	int x,y,test;
	cin>>test;
	while(test--){
	cin>>x>>y;
	cout<<solve(x,y,8)<<endl;
	}
	return 0;
}
