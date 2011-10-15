// bY superHero Batman
#include<iostream>
#include<cstdlib>
#include<math.h>
#define MAX 4
using namespace std;

int main()
{
	long int T,X,Y,MAT[MAX][MAX]={ 0,1,2,3,
											 1,0,3,2,
											 2,3,0,1,
											 3,2,1,0};
	long int tmp1=0,tmp2=0;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>X>>Y;
		tmp1=X/4;
		tmp2=Y/4;
		if(tmp1==tmp2)
				cout<<MAT[X%4][Y%4]<<endl;
		else if (tmp1>0 && tmp2==0)
			cout<<MAT[X%4][Y%4]+(4*abs(tmp1))<<endl;
		else if (tmp1==0 && tmp2>0)
			cout<<MAT[X%4][Y%4]+(4*abs(tmp2))<<endl;
		else if (tmp1>0 && tmp2>0)
		{
			cout<<MAT[X%4][Y%4]+4*tmp2
			+4*tmp1<<endl;
		}
		
		
		tmp1=0;tmp2=0;
	}
}

