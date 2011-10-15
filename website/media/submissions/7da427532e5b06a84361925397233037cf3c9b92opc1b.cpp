#include<iostream>

using namespace std;


int funct(int , int, int);

main()
{
    
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;

        cout<<funct(x,y, 1048576)<<endl;


    }
}

    int funct( int x, int y,int N)
    {

        if(y==0)
            return x;
        else if(x==0)
            return y;

        if(x>=N/2 && y>= N/2)
        {
            return funct(x-N/2 , y-N/2 , N/2);

        }

        else if(x>=N/2 && y<N/2)
        {
            return funct(x, y , N/2);
        }

        else if(x<N/2 && y>= N/2)
        {
            return funct(x+N/2, y-N/2 , N/2);
        }

        else if(x<N/2 && y< N/2)
        {
            return funct(x,y,N/2);
        }
    }


    
