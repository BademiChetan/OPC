#include <iostream>
#include <math.h>
using namespace std;
int call(int x, int y)
{
    if( x==y )
       return 0;
    else
       return 1;
} 
    
int find(int i,int x,int y)
{
    int plus =0;
    if(i==1)
        return call(x,y);
    int twopower = pow(2,i-1);
    if(x > twopower && y > twopower)
    {
        plus = 0;
        x-=twopower;
        y-=twopower;
    }
    else if((x > twopower && y <= twopower))
    {
        plus = pow(2,i-1);
        x-=twopower;
    }
    else if((y > twopower && x <= twopower))
    {
        plus = pow(2,i-1);
        y-=twopower;
    }   
    else
        plus = 0;
    return find(i-1,x,y)+plus;    
}


int main()
{
    int t,a[10000];
    cin>>t;
    for (int j = 0;j<t;j++)
    {
        int x,y,max;
        cin>>x>>y;
        x++;
        y++;
        if(x>y)
            max = x;
        else
            max = y;
        int i = 1;
        while(i<max)
        {   
            if( pow(2,i)>max)
                break;
            i++;
        }
        a[j]=find(i,x,y);
    }
    for ( int i=0;i<t;i++)
        cout<<a[i]<<endl;
    return 0;
}

