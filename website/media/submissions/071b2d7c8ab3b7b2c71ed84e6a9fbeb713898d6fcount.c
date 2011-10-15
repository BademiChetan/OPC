#include<stdio.h>
#include<stdlib.h>
int main()
{
int t,a,i,*r,j,b,m,k,count=0,e,f,l;
char *n,*s;
scanf("%d",&t);
printf("\n");
for (i=0;i<t;i++)
{
scanf("%d",&a);
n = (char *)malloc((a+1) * sizeof (char));
    scanf("%s",n);
scanf ("%d",&b);
r=(int *)malloc(b * sizeof (int));
for (j=0;j<b;j++)
    {
    scanf("%d",&m);
    scanf("%d",&k);
        e=0;
        while(n[e]!='\0')
            {
                f=0;
                if(n[e]==n[m+f])
                    {
                        l=e+1;
                        while(n[l]!='\0')
                        {
                            if(n[l]!=n[m+f+1])
                            break;
                            f++;
                            l++;
                        }
                    if(f==k)
                    count=count+1;
                    }
            e++;
            }
        r[j]=count;
        count=0;
        free(s);

    }
for (j=0;j<b;j++)
printf("%d\n",r[j]);
free(n);
}

free(r);
return 0;
}
