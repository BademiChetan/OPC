#include<stdio.h>
#include<string.h>
int main()
{int t;int y;
scanf("%d",&t);
for(y=0;y<t;y++)
    {int n;
    int count,flag;
    scanf("%d",&n);
    char sample[n];
    int i;
    int j;
    int l;
int r;
    scanf("%s",sample);
    int check;
    scanf("%d",&check);
    int m[check],k[check];
   for(i=0;i<check;i++)
    {scanf("%d%d",&m[i],&k[i]);
    }
    char a[5000];
    for(r=0;r<check;r++)
    {   count=0;
        for(i=0;i<n;i++)
    {

        if(i==m[r])
        {
            for(j=0;j<k[r];j++)
            {
                a[j]=sample[i];
                i++;
            }break;

        }
    }

for(j=0;j<(n-k[r]+1);j++)
         {flag=0;
             for(l=0;l<k[r];l++)
             {
                 if(a[l]!=sample[j+l])
                 {
                     flag=1;break;
                 }
             }if(flag==0)
             count++;
         }



      printf("%d\n",count);
      }






    }
    return 0;
}
