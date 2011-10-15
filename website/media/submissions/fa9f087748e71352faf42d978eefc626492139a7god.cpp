#include<iostream>
#include<math.h>
using namespace std;

 //long int big[1000000][1000000];
 
int main()
{
   
   long int t;
 int a[4][4]={0,1,2,3,1,0,3,2,2,3,0,1,3,2,1,0};
   // scanf("%d",&t);
   cin>>t;
  
    do
    {
              long int x,y;
              cin>>x>>y;
              x=x%4;
              y=y%4;
              
              cout<<a[x][y]<<endl;
              
              
              
              
              
      //int b
      t--;
    }while(t!=0);
    
    
    
   // getch();
 
    return 0;
}


