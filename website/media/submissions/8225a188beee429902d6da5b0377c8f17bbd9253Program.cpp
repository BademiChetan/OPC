#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
class Item
    {
	public :int cost,value,F;
	
	public: Item()
        {
			/*
            
			*/
        }
			void getIt()
			{
				cin>>cost;
            cin>>value;
            cin>>F;
			}

    };
const int maxn=1100000;
Item l[6];

Item r[6];
int values[maxn];
int cost[maxn];
int n;
int res=-1;
int ind=0;
int Budget;
int len;
pair<int,int> t[maxn];
void rec(int at, int value, int sumCost) {
        if(sumCost>Budget)
            return;
        if(at==n/2)
        {
            cost[ind]=sumCost;
            values[ind++]=value;
            return;
        }
        for(int x=0;x<=l[at].F;x++)
        {
           rec(at+1,value+l[at].value*x,sumCost+l[at].cost*x);
        }
    }
    void rec2(int at, int value, int sumCost) {
        if(sumCost>Budget)
            return;

        if(at==n-n/2)
        {
            int remains=Budget-sumCost;
        int low=0;
        int high=len;
        while(high-low>1)
        {
            int mid=(low+high)>>1;
            if(cost[mid]<=remains)
                low=mid;
            else
                high=mid;
        }
        res=max(res,value+values[low]);
            return;
        }

        for(int x=0;x<=r[at].F;x++)
        {
           rec2(at+1,value+r[at].value*x,sumCost+r[at].cost*x);
        }
	}
	


int main()
{	   
 
		int T;
		cin>>T;
        for(int test=1;test<=T;test++)
        {
			
			cin>>n;
            cin>>Budget            ;
            len=1;
			
            for(int i=0;i<n/2;i++)
            {
				l[i].getIt();
                len*=l[i].F+1;
            }            
            for(int i=0;i<n-n/2;i++)
            {
				r[i].getIt();
            }
            //set=new HashMap<Integer,Integer>();
			for(int i=0;i<maxn;i++)
			{
				values[i]=cost[i]=0;
			}
            ind=0;
            rec(0,0,0);
            for(int i=0;i<len;i++)
				t[i]=make_pair(cost[i],values[i]);
            sort(t,t+len);           
            int curMax=0;
            for(int i=0;i<len;i++)
            {
				cost[i]=t[i].first;
				curMax = max(curMax,t[i].second);
                values[i]=curMax;
            }
            rec2(0,0,0);
            cout<<res<<endl;
        }
    }

    

    

    