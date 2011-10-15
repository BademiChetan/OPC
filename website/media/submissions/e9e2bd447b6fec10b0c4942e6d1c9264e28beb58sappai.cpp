#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stdlib.h>

using namespace std;

int main(){
   int t;
   int arr[200];
   cin>>t;
   while(t--){
       
   
   int sum=0;
       int n;
       cin>>n;
       int i;
       for(i=1;i<=n;i++){
         cin>>arr[i];
         sum+=arr[i];
         
         }
        n--;
        sum-=(n*(n+1)/2);
        if(sum%2==0)
          cout<<"LOSE"<<endl;
        else
          cout<<"WIN"<<endl;
   
   
   
}
    
    
    return 0;
}
