#include <stdio.h>
int main()
{
    int n,i=0;
    long int temp,x,y;
    scanf("%d",&n);
    long int inputs[n][2];
    while(i<n)
    {
        scanf("%d",&inputs[i][0]);
        scanf("%d",&inputs[i][1]);
        i++;
    }
    i=0;
    while(i<n)
    {
        x=inputs[i][0];
        y=inputs[i][1];
        if(y>x) 
        {
            temp=x;
            x=y;
            y=temp;
        }
        if(x==y)
            printf("0\n");
        else if((x-2)%4==0)
            printf("%d\n",x-((y/2)*2)+y%2);
        else if((x-3)%4==0)
            printf("%d\n",x-((y/2)*2)-y%2);
        else if((x-1)%4==0&&(x-y)!=1)
            printf("%d\n",x+((y/2)*2)-y%2); 
        else if((inputs[i][0])%4==0)
            printf("%d\n",x+((y/2)*2)+y%2);   
        else
            printf("1\n");
        i++;
    }
    return 0;
}
