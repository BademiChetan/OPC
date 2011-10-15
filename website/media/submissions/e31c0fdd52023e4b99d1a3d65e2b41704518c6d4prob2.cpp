#include<cstdio>
#include<cstring>
using namespace std;



int save[101];

int main(){
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int n;
     scanf("%d",&n);     
     int total=0;     
     memset(save,0,sizeof(save));
     for(int i=0;i<n;i++)
     {
      scanf("%d",&save[i]);       
     }
     total=save[0];
     for(int i=1;i<n;i++)
     {
     total = total+save[i]-i;
     }
  
     if(total%2==0)printf("LOSE\n");
     else printf("WIN\n");
    }
    
    return 0;
    }
