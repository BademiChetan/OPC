//      1.cpp
//      
//      Copyright 2011 Archit Bansal <architb@iitk.ac.in>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//      
//      


#include <iostream>
using namespace std;

int ans(int x, int y)
{
	if(x%2 == 0)
	{
		if(y-x == 0)	return 0;
		else if(y-x == 1)	return 1;
		else
		{
			return x+y;
		}
	}
	else
	{
		if(y%2 == 0)	return ans(x-1,y+1);
		else
		{
			return ans(x-1,y-1);
		}
	}
}
	
int main()
{
	int i,t,x,y;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>x>>y;
		cout<<ans(x,y)<<endl;
	}
	return 0;
}

