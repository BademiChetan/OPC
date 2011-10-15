#include<stdio.h>
int main()
{
    int n,i,unit=2,j;
    scanf("%d",&n);
    
    int cal[n][2];
    for(i=0;i<n;i++)
    {
                    
                scanf("%d %d",&cal[i][0],&cal[i][1]);
                    
    }
    for(i=0;i<n;i++)
    {
                    for(j=0;j<cal[i][0];j++)
                    {
                                            unit=unit*unit;
                                            }
                                            printf("%d\n",unit%cal[i][1]);
                                            unit=2;
}
    
    

    return(0);
}
