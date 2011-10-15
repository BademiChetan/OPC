#include<iostream>
//#include<conio.h>
using namespace std;
int main(){
    int t,i,j,result=2;
    cin>>t;    
    int test[t][2];
    for(i=0; i<t; i++){
          for(j=0; j<2; j++)      
                  cin>>test[i][j];
    }
    for(i=0; i<t; i++){
            for(j=0; j<test[i][0]; j++ ){
                 result = result * result;
            }
            cout<<result<<endl;
            result=2;        
    }
    //getch();
    return 0;
}
