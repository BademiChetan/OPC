#include<iostream>
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
              
            //  for(int x=0;x<15;x++)
            //  {
            //          for(int y=0;y<15;y++)
            //          {
              
              
              long int x1=x%4;
              long int y2=y%4;
              if((x/4)==(y/4))
                          cout<<a[x1][y2];
              else
              {
                  //long int flag=(x+y)/4;
                  
                  cout<<a[x1][y2]+4*(x/4+y/4);
                  }
              
    //int b
   // cout<<";
     //     }
          cout<<endl;
      //    }
          
      t--;
    }while(t!=0);
    
    
    
   //getch();
 
    return 0;
}


