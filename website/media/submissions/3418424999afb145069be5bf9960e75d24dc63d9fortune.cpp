#include<iostream>
//#include<conio.h>
using namespace std;
int main(){
    int t,i,j;
    cin>>t; 
    int out[t],test[t][2];
    out[0]=2;
    for(i=0; i<t; i++){
          for(j=0; j<2; j++)      
                  cin>>test[i][j];
          for(int k=0; k<test[i][0]; k++)
          {
                  out[i] = out[i]*out[i];
          }
          out[i+1]=2;
    }
    for(i=0; i<t; i++)
             cout<<out[i]<<endl;
   
    //getch();
    return 0;
}
