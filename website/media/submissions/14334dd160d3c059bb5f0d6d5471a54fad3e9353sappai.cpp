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
       for(i=1;i<power;i++){
             temp=((temp%modulo) * (temp%modulo))%modulo;
       }
       
       cout<<temp<<endl;
    }
    
    return 0;
}
