// bY superHero Batman
#include<iostream>

using namespace std;

int main()
{
	long int T,X,Y,max=0;
	cin>>T;
	long int rT[T][2];
	
	for(int i=0; i<T; i++)
	{
		cin>>X>>Y;
		rT[i][0]=X;
		rT[i][1]=Y;
		if(max<X)
			max=X;
		if(max<Y)
			max=Y;
	}
	max++;
	for(int i=0; i<T; i++)
	{
		int j=rT[i][0];
		if(rT[i][0]==rT[i][1])
			cout<<0<<endl;
		else if(rT[i][0]<rT[i][1])
			cout<<max-rT[i][1]<<endl;
		else if(rT[i][0]>rT[i][1])
			cout<<Y<<endl;
		
	}
}

