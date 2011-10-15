#include<iostream>
#include<math.h>
using namespace std;

double abc(double a, double c)
{
int result = static_cast<int>( a / c );
return (a - static_cast<double>( result ) * c);
}
int main()
{
double x[1000][2];
double y;
    int t,j;
    int i;
    double b;
   
    cin>>t;
    for(i=0;i<t;i++)
    {
    cin>>x[i][0]>>x[i][1];
    }
                       
    for(j=0;j<t;j++)
    {
    y=pow(2,x[j][0]);
    b=pow(2,y);
   
    cout<<abc(b,x[j][1])<<endl;
    }
  return 0;                   
   
}





