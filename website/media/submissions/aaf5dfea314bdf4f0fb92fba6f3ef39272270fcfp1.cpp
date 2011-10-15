#include <map> 
#include <set> 
#include <cmath> 
#include <queue> 
#include <vector> 
#include <string> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <cfloat>
#include <ctime> 
#include <climits>
#include <iomanip>
using namespace std; 

typedef long long int64; 
typedef unsigned long long uint64;

int find(int x, int y)
{
    if(x < y)
        {    
            int t = x;
            x = y;
            y = t;
            
        }
    else if(x==y)
	  	return 0;
    double xLog;
    int temp;
    if(x > 1)
    {
       /* xLog = log2(x);
        temp = (int)floor(xLog);
		temp = pow(2,temp);*/
	   temp = 1;
	   while(temp<x)
		 temp = temp<<1;
        if(x == temp)
    	    return temp-y;
		else
		  temp =temp>>1;
    	if(y <= temp)
        	return find(x - temp , y) + temp;
    	else
	        return find(x - temp , y - temp);	
    }
    else if(x == 2)
    {
        if(y==1)	
		  return 2;
		else
		  return 1;
    }
    else
        return 1;
        
}


int main(int argc, char * argv[])
{
    int count, x , y;    //Number of Test cases
    
    scanf("%d",&count);
    for(int k=0;k<count;k++)
    {
        //Take Test case as input.
        scanf("%d",&x);
        scanf("%d",&y);
        
        printf("%d\n",find(x+1,y+1));
        
    }
    return 0;
}
