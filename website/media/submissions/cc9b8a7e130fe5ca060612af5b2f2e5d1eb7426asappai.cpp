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
    unsigned long long i,power,modulo,temp=1;
    cin>>t;
    while(t--){
       cin>>power>>modulo;
       temp=2;
       for(i=0;i<power;i++){
             temp=(temp *temp)%modulo;
       }
       
       cout<<temp<<endl;
    }
    
    return 0;
}
