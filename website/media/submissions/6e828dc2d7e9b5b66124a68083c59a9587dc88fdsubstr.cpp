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
    char ss[50005];
    scanf("%d",&s);
    while(s--){
    scanf("%d %s",&len,&ss);
//    int t;
  //  cin>>s;
    string str(ss);
    

    cin>>t;
    int start,end;
    int count;
    while(t--){
        count=0;
        scanf("%d%d",&start,&end);
        int i;
        string s1,s2;
        s1=str.substr(start,end);
        for(i=0;i<len;i++){
              s2=str.substr(i,end);             
             if(s1==s2)
                 count++;
        
        }
        printf("%d\n",count);
    
    
    }   
}
    return 0;
}
