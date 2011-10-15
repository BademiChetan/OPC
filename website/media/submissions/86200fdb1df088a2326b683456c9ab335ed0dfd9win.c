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
                    j=0;
                    while(j<cal[i][0])
                    {
                    unit=unit*unit;
                    j++;
                    }
                    
                    printf("%d\n",unit%cal[i][1]);
         unit=2;                          
}
    
    getch();

    return(0);
}
