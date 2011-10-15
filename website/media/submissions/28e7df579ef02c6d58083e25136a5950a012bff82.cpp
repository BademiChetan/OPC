#include<cstdio>
#include<algorithm>
using namespace std;
int odd,even,n;
int dp[250][250][2];//dp[odd][even]
void solve()
{
    dp[1][0][0]=1;
    dp[0][1][0]=0;
    dp[1][0][1]=1;
    dp[0][1][1]=0;
    for(int l=2;l<=(100);l++)
    {
        for(int i=0;i<=l;i++)
        {
            int m=l-i;
            if(i==0)
            {
                dp[i][m][0]=dp[i][m-1][1];
                dp[i][m][1]=dp[i+1][m-2][0];
            }
            else if(m==0)
            {
                dp[i][m][0]=dp[i-2][m+1][1];
                dp[i][m][1]=dp[i-1][m][0];
            }
            else
            {
                if(i<2)
                    dp[i][m][0]=dp[i][m-1][1];
                else
                    dp[i][m][0]=min(dp[i-2][m+1][1],dp[i][m-1][1]);
                if(m<2)
                    dp[i][m][1]=dp[i-1][m][0];
                else
                    dp[i][m][1]=max(dp[i-1][m][0],dp[i+1][m-2][0]);
            }
        }
    }
}
void print()
{
    int i,j;
    printf("even \n");
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            printf("%d ",dp[i][j][0]);
        printf("\n");
    }
    printf("odd \n");
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            printf("%d ",dp[i][j][1]);
        printf("\n");
    }
}
int main()
{
    int i,j,k,t;
    odd=even=100;
    solve();
    //print();
    scanf("%d",&t);
    while(t--)
    {
        odd=even=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            if(j&1)
                odd++;
            else
                even++;
        }
        if(dp[odd][even][1])
            printf("WIN\n");
        else
            printf("LOSE\n");
    }
    return 0;
}
