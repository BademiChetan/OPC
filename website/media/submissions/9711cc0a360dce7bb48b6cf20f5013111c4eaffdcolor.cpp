#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char **argv)
 {
  ifstream input;
  ofstream output;
  input.open(argv[1]);
  output.open(argv[2]);
  
  int testcount;
  input>>testcount;
  long int x,y;
  int N=max(x,y);
 for (int i=0;i<testcount;i++)
   {
     input>>x;
     input>>y;
   ////////////checking for negative values//////////// 
     if(x<0||y<0)
        {
          output<<"Invalid Test case"<<endl;
          continue;
        }
  ////////////////////////////////////////////////////
     if(x==y)
        {
         output<<0<<endl;
         continue;
        }
     long int value=0; 
     while(y>x)
       {  x++;
          value++;
       }
     while(y<x)
       {  x--;
         value--;
       }
     if(value<0)
         value=N+value;
     output<<value<<endl;
    }
   return 0;
 }
