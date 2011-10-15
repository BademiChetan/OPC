#include<stdio.h>
int main()
{
    int n,i=0,unit=2,j,z;

    scanf("%d",&n);
    
    int cal[n][2];
    while(i<n)
    {
                    
                scanf("%d %d",&cal[i][0],&cal[i][1]);
             i++;       
    }
    for(i=0;i<n;i++)
    {
                             unit=2;            
                    hai:
                    unit=unit*unit;
                    j++;
                    if(j<cal[i][0])
                    goto hai;
                      printf("%d\n",unit%cal[i][1]);
                    }

        return(0);
              
}
