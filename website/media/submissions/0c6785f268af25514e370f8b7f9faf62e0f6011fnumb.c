#include<stdio.h>
int main()
{ int t,n,i,board[100],turn=0,j;
 scanf("%d",&t);
  while(t--)
 {  scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    { scanf("%d",&board[i]);
    }
    for(i=0;i<=n-2;i++)
    { turn++; 
      board[i+1]=board[i]+board[i+1]-turn;
      board[i]=0;
       
    }
      if(board[i]%2==0)
     printf("LOSE");
    else
     printf("WIN");
 }
return 0;
}
