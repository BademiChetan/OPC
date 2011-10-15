#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

int rec(int x, int y) {
        if(x==0)
            return y;
        x--;
        int k=0;
        while(x>(1<<k)-1)
        {
            x-=1<<k;
            k++;
        }
        int res=(y/(1<<(k+1)))*(1<<(k+1));
        if(y%(1<<(k+1))<1<<k)
            res+=1<<k;
        res+=rec(x,y%(1<<k));
        return res;
    }

int main()
{	   
 
int T;
cin>>T;
        for(int test=1;test<=T;test++)
        {
			int x,y;
			cin>>x>>y;
            
            int res=rec(x,y);
            cout<<res<<endl;
        }
}

    

    

    