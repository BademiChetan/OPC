#include<iostream>
//#include<conio.h>
using namespace std;

int main(){
    int a;
    int ch;
    //cout<<"Enter the test cases : ";
    cin>>ch;
    //cout<<"Enter the limit "; 
    //cin>>a;
    int num[a][a],count=0;
    for(int i=0;i<a; i++){
                
         for(int j=0; j<a; j++){
                 if(i==0)num[i][j]=j;
                 else if(j==0) num[i][j]=i;        
                 else{
                      num[i][j]=num[i-1][j]+1;
                      if(num[i][j]>a-1)
                                     num[i][j]=0;     
                 }
         }                     
    }
    int test[ch][2];
    for(int i=0; i<ch; i++){
          for(int j=0; j<2; j++)      
                  cin>>test[i][j];
    }
    for( int i=0; i<ch; i++  ){
         cout<<num[test[i][0]][test[i][1]]<<endl;
    }
    //getch();
    return 0;
}
