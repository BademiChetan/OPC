#include <cstdio>
#include <algorithm>
using namespace std;
int diff[1000001];
void copy(int a);
int main(){
  int newNum=4;
  diff[0]=2;
  int index=1;
  while(index<1000001){
    diff[index]=newNum;
    newNum*=2;
    copy(index);
    index+=index+1;
  }
  //for(int i=0;i<20;i++) printf("\n %d",diff[i]);
  int t,x,y;
  scanf("%d",&t);
  for(int test=0;test<t;test++){
    scanf("%d",&x);
    scanf("%d",&y);
    if(y<x) swap(x,y);
    while(x>0){
      //printf("\n diff=%d  x=%d y=%d",diff[x-1],x,y);

      int a=y/diff[x-1];
      int b=y%diff[x-1];
      y=a*diff[x-1]+(diff[x-1]-b);
      x--;
    }
    printf("%d\n",y);
  }
  return 0;
}

void copy(int a){
  for(int i=0;i<a;i++){
    if(a+i+1>1000000) return;
    diff[a+i+1]=diff[i];
  }
}

