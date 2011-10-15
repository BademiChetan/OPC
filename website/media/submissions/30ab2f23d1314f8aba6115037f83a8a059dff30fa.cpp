#include<iostream>
#include<stdio.h>
using namespace std ;

int main()
{
 int n,m ;
 int runs ;
 
 
 cin >> runs ;
 while(runs--)
 {
  cin >> n >> m ;
  int ret = n ^ m ;
  printf("%d\n",ret) ;
 }
 return 0 ;
}
