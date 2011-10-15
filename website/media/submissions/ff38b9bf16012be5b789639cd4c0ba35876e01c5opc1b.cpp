#include<iostream>

using namespace std;

int a;
int funct(int , int, int);

main()
{
    
    int t,x,y;
    cin>>t;
    while(t--)
    {
        a=0;
        cin>>x>>y;

        cout<<a+funct(x,y, 1048576)<<endl;


    }
}

    int funct( int x, int y,int N)
    {

        if(y==0)
            return x;
        else if(x==0)
            return y;

        if(x>=N/4 && y>= N/4)
        {
            return funct(x-N/4 , y-N/4 , N/2);

        }

        else if(x>=N/4 && y<N/4)
        {
            a+=N/4;
            return  funct(x-N/4, y , N/4);
        }

        else if(x<N/4 && y>= N/4)
        {
            a+=N/4;
            return funct(x, y-N/4 , N/2);
        }

        else if(x<N/4 && y< N/4)
        {
            return  funct(x,y,N/2);
        }
    }


    
