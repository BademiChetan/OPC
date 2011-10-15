
#include <stdio.h>

int main()
{
int x, y, n;
scanf("%d", &n);

int gh=0;
int ans[n];
while(gh<n)
{
scanf("%d", &x);
scanf("%d", &y);


int a[x+1][y+1], b[x+1][y+1][x+y];
int flag, pt, point, m, t;
int i, k, j;
int w, h, l, s;
a[0][0]=0;




for (i=0; i<=x; i++)
{
    for(j=0; j<=y; j++)
    {
        k=0;
        m=0;
        while(m<j)
        {
            b[i][j][k] = a[i][m];
            m++;
            k++;
        }
        
        m=0;
        
        while(m<i)
        {
            b[i][j][k] = a[m][j];
            m++;
            k++;
        }
        
        while(k<x+y)
        {
            b[i][j][k]=-1;
            k++;
        }
  
        for(pt=0; pt<=k; pt++)
        {   
            flag = 0;
    
            for(t=0; t<k; t++)
            {
                if (pt==b[i][j][t])
                {
                    flag = 1;
                    goto aha;
                }
                
            }
            
            if (flag==0)
            {
                point = pt;
                goto out;
            }
            
         
            aha:
            s = 0;
         }
        
        out:
        a[i][j] = point;
    }
}    


ans[gh]= a[x][y];
gh++;
}

gh = 0;

while(gh<n)
{
printf("%d\n", ans[gh]);
gh++;
}

return 0;
}
