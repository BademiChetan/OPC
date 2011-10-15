#include<stdio.h>
int main()
{
   int i,j,l,t,n,x,y,k, board[100][100];
n=10;
   for(i = 0; i<n; i++)
    {
     k = i;
    for(j = 0; j<n; j++)
    {
      if ( k == n)
	{
	 k = 0;
	}
       board[i][j] = k;
      k++;
    }
    printf("\n");

    }
    scanf("%d",&t);
    for(l = 0; l<t; l++)
    {
      scanf("%d",&x);
      scanf("%d",&y);
      if(x<n && y<n)
      printf("%d\n",board[x][y]);

	}
   return 0;

}



