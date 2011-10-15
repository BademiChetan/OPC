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

int getmax(long long a , long long b)
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
	int i,j,n,count,t;
    int a,b,c,w,k;
	cin>>t;
	getchar();
	while(t--)
	{
	cin>>n>>w;
	getchar();
	vector<int> wi(n*15);
	vector<int> vi(n*15);
	
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
	int W = w + 1;
	vector< vector<int> > m(k,W);
	
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
	}
	return 0;
}

