#include<iostream>
//#include<conio.h>
using namespace std;

int main(){
    int t,n;
    char word[n];
    int ch;
    cin>>t>>n>>word>>ch;    
    int test[ch][2];
    for(int i=0; i<ch; i++){
          for(int j=0; j<2; j++)      
                  cin>>test[i][j];
    }
    int count=0;
    for(int i=0; i<ch; i++){
            char t=word[i];
            for( int j=test[i][0]; j<n; j++ ){
                  if(t==word[j])
                                count++;
            }
             cout<<count<<endl;
             count=0;       
    }   
    //getch();
    return 0;
}
