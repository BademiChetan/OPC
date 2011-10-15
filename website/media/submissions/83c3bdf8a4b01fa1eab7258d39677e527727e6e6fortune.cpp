#include<iostream>
//#include<conio.h>
using namespace std;
int main(){
    int t;
    cin>>t;    
    int test[t][2];
    for(int i=0; i<t; i++){
          for(int j=0; j<2; j++)      
                  cin>>test[i][j];
    }
    int result=2;
    for(int i=0; i<t; i++){
            for( int j=0; j<test[i][0]; j++ ){
                 result = result * result;
            }
            cout<<result<<endl;
            result=2;        
    }
    getch();
    return 0;
}
