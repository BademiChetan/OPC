#include<stdio.h>
#include<stdlib.h>
int main()
{
                  int T;
                  int N = 100;
                  scanf("%d" , &T);
                  int array[N][N];
                  int i,j;
                  for(i=0 ; i < N ; i++)
                  {
                          for(j=0; j < N ; j++)
                          {
                                   if( (j-i) >= 0 )
                                   array[i][j] = j-i;
                                     else 
                                   array[i][j] = j-i+N;                                       
                                  
                          }
                  }
                 int attempt  =1;
                 int *x;
                 int *y;
                 x = (int*)malloc(T * sizeof (int));
                 y = (int*)malloc(T * sizeof (int));
                 int *xp;
                 int *yp;
                 xp = x;
                 yp = y;
                 while(attempt <=T)
                 {
                               scanf("%d %d" , x,y);
                               x++ ; y++;
                               attempt++;
                 }
                 attempt = 1;
                 while(attempt <= T )
                 {
                               printf("%d\n" , array[(*xp)][(*yp)]);
                               xp++;
                               yp++;
                               attempt++;
                 }
               
                 return 0;
                                    
}
