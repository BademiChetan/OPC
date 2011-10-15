#include<iostream>
#include<math.h>
using namespace std;

int main()
{
   int x[1000][2];double y;
    int t,j;
    int i;
  int b;
    
    cin>>t;
    for(i=0;i<t;i++)
    {
    cin>>x[i][0]>>x[i][1];}
                        
    for(j=0;j<t;j++)
    { 
    y=pow(2,x[j][0]);
    b=pow(2,y);
    cout<<(b%x[j][1])<<endl;
    }
                      
    
}
