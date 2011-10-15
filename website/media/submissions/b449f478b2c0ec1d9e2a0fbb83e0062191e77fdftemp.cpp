#include<iostream>
using namespace std;
#include<conio.h>

int main()
 {
          int t, i;
          long long n, k, sum, quo;
          
          cin>>t;
          for(i=0;i<t;i++)
           {
                          cin>>n>>k;
                          sum=n*(n+1)/2;
                          quo=sum/k;
                          
                          cout<<(sum-quo)%1000000007<<endl;
           }
          getch();
          return 0;
 }
