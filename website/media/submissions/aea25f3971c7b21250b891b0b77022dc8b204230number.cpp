#include<iostream>
#include<fstream>
using namespace std;
int main()
{
ifstream i("i.dat",ios::binary);
ofstream o("o.dat",ios::binary);

int t,tp,n,x;
long s=0;
i>>t;
for(int j=1;j<=t;j++)
{       s=0;
        i>>n;
for(int k=1;k<=n;k++)
 {i>>x;
        s+=x;
        }
        tp=n/2;
        t=(tp*(tp+1))/2;
        if((s-t)%2!=0)
  o<<"WIN";
        else
        o<<"LOSE";
  
            
}
return 0;
}
