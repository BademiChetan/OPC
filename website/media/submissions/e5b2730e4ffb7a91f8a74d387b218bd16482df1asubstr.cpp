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
bool check(string original, int from,int to, int i){
     for(int j=from;j<to;j++){
            if(original[j]==original[i])
                i++;
            else 
               return 0;
     }
     return 1;


}

int main(){
    int t,s;
    int len;
    string str;
    cin>>s;
    while(s--){
    cin>>len>>str;
//    int t;
  //  cin>>s;
    

    cin>>t;
    int start,end;
    int count;
    while(t--){
        count=0;
        cin>>start>>end;
        
        int i;
        for(i=0;i<len;i++){
             if(check(str,start,start+end,i))
                 count++;
        
        }
       cout<<count<<endl;
    
    
    }   
}
    return 0;
}
