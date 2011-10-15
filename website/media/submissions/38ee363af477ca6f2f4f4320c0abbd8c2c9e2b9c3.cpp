# include <iostream>
#include<math.h>
using namespace std;
//long long int dp[1000000000];
long long int cal_power(long long int , long long int);

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k;
        cin>>n;
        cin>>k;
        
        long long int i;
        long long int result =2;
        //for(i=1;i<=n;i++)
        {
        
            //result = (result%k*result%k)%k; 
            result = cal_power(n,k);
        }    
    cout<<result<<endl;

    }//end of test cases

}

long long int cal_power(long long int a,long long int k)
{
    if(a==1) return 4;
    else
    {
      int  c =cal_power(a-1,k)%k;
      c= c*c;
     return c%k;  
    }

}
