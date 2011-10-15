#include <iostream>
#include <algorithm>
using namespace std;
long long t,n,k;

int kq(long long n, long long k){
     long long hs = 2;
     long long s = 1;
     while (n>0)
           {
                if (n%2==1) s = (s*hs) % k;

                hs = (hs*hs)% k;
                n = n/2;
                }
return (s);
}
                
                   

int main() 
{
    cin >>t;
    int i;
    for (i=1; i<t+1; i++)
        {
              cin >> n >>k;
              cout << kq(n+1,k) << endl;
              }
    return 0;

}
