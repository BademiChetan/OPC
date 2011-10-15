#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#define s(c) scanf("%d",&c);
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;


int main()
{
  int t;
  int a,b;
  s(t);
  while(t--){
   scanf("%d %d",&a,&b);
   printf("%d\n",b-a); 
  }     
}
