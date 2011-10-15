#include<iostream>
#include<math.h>
using namespace std;

int main()
{
   double x[1000][2];double y;char ch;
    int t,j;
    int i;
double b;
    
    cin>>t;
    for(i=0;i<t;i++)
    {
    cin>>x[i][0]>>x[i][1];}
                        
    for(j=0;j<t;j++)
    { 
    y=pow(2,x[j][0]);
    b=pow(2,y);
    cout<<fmod(b,x[j][1])<<endl;
    }
                      
    
}
