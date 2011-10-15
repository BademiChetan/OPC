// chemicals.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int getmax(int a , int b)
{
 int x = a;
 int y = b;
 if(x >= y)
	 return x;
 else
	 return y;

}

int main()
{
	int i,j,k,n,count,t,w;
	int a,b,c;
	cin>>t;
	getchar();
	cin>>n>>w;
	getchar();
	vector<long long> wi(n*15);
	vector<long long> vi(n*15);
	vector<int> fi(n*15);
	i = 0;
	j = 0;
	k = 0;
	while(i < n)
	{
		a = 0;b= 0; c = 0;
		cin>>a>>b>>c;

	    j = 0;
		while(j < c)
		{
			wi[k] = a; vi[k] = b; 
			j++;
			k++;

		}
      i++;

	}
	
	vector< vector<long long> > m(k ,w+1);
	
	n = k;
	for(i=0;i<=n-1;i++)
	{
		for(j=1;j<=w;j++)
		{
			if(wi[i] > j)
			{
				if(i-1  >= 0)
				{
					m[i][j] = m[i-1][j];
				}
				else
					m[i][j] = 0;
			}
			else
			{
				if(i-1 >= 0 && j - wi[i] > 0){
					m[i][j] = getmax(m[i-1][j] , m[i-1][j-wi[i]] + vi[i]);}
				else
				{if(i -1 == 0 && j - wi[i] <=0)
					m[i][j] = getmax(m[i-1][j],vi[i]);
				 else
					m[i][j] = vi[i];
				}
		  }

		}
	}
	cout<<m[k-1][w]<<endl;
	return 0;
}

