# include <stdio.h>

int main()
{
    int i,j,temp;
    int t, sum, n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        sum = 0;
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&temp);
            sum+=(temp-j);                 
        }                
        if(sum%2==0)
                    printf("LOSE\n");
        else
            printf("WIN\n");            
    }
return 0;    
}
