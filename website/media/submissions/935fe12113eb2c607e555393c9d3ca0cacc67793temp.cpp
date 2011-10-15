#include<iostream>
using namespace std;

int main()
 {
          int t, i;
          long long n, k, result, j;
          
          cin>>t;
          for(i=0;i<t;i++)
           {
                          cin>>n>>k;
                          result=2;
                          
                          for(j=0;j<n;j++)
                                          result=(result*result)%k;
                          cout<<result<<endl;
           }
          return 0;
 }
