
#include <stdio.h>
#include <malloc.h>

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


int** a;
int*** b;
a = malloc((x+1)*sizeof(int*));
b = malloc((x+1)*sizeof(int**));

int gen, bla;

for(gen=0; gen<x+1; gen++)
{
    a[gen] = malloc((y+1)*sizeof(int));
    b[gen] = malloc((y+1)*sizeof(int*));

    for(bla=0; bla<x+y; bla++)
        b[gen][bla] = malloc((x+y)*sizeof(int));
}


int flag, pt, point, m, t;
int i, k, j;
int w, h, l, s;


if (x==0)
{
for(j=0; j<=y; j++)
    a[0][j] = j;
goto end;
}    

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

end:
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
