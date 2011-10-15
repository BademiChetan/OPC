#include <iostream>
using namespace std;
unsigned int pow2(unsigned int x)
{ unsigned int r=1;
         while(x--)
          r*=2;
          return r;
          }
          
int main()
{int T;
cin>>T;
while(T--)
{

    unsigned int n;
    cin>>n;
    unsigned int k;
    cin>>k;
    unsigned int res2,result;
    unsigned int res1=1;
    unsigned int x=n/4;
   unsigned int rem=n%4;//int arr[20];
    while(x>0)
     {   // arr[0]=6;arr[1]=5;arr[2]=5;arr[3]=3;arr[4]=6;
              res1=((res1%k)*(65536%k))%k;
              x--;
     }
     if(rem) res2=pow2(rem);
       result=(res1!=0)?(((res1%k)*(res2%k))%k):(res2%k);
     cout<<result<<endl;
     }
   // system("pause");
    return 0;
}
