//iPS

#include<cstdio>

int main()
{
    int t;
    int n;
    int ne;
    int temp;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        ne=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if (temp%2)
            {
                ne--;
            }
            else
            {
                ne++;
            }
        }
        if (ne<0)
        {
            temp=0;
            ne=-ne;
        }
        else
        {
            temp=1;
        }
        ne%=4;
        if ( (temp && (ne==2 || ne==3)) || (!temp && (ne==2 || ne==1)) )
        {
            printf("WIN\n");
        }
        else
        {
            printf("LOSE\n");
        }
    }
    return 0;
}

