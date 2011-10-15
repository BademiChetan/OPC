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
              long int x1=x%4;
              long int y2=y%4;
              if((x/4)==(y/4))
                          cout<<a[x1][y2]<<endl;
              else
              {
                  //long int flag=(x+y)/4;
                  
                  cout<<a[x1][y2]+4*(x/4+y/4)<<endl;
                  }
              
    //int b
      t--;
    }while(t!=0);
    
    
    
   // getch();
 
    return 0;
}


