#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;




int main(){
    
    int x,y,t;
    
    scanf("%d",&t);
    while(t--)
    {
     scanf("%d%d",&x,&y);
     int a=x,b=y;
     if(a<b)swap(a,b);  
     printf("%d\n",a-b);        
    }
    
    return 0;
    }
