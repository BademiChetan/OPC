#include<stdio.h>
#include<string.h>

int qv[50000][2]={0};
int ans[500000]; char q1[50000],q2[50000];char str[50000];
int main()
{

int t;int cfl=0;
scanf("%d",&t);
int i;
for(i=0;i<t;i++)
{
int n,q;
scanf("%d",&n);

scanf("%s",&str);

scanf("%d",&q);
int j,k;
for(j=0;j<q;j++)
{
    scanf("%d%d",&qv[j][0],&qv[j][1]);
}
int fl=0;
for(j=0;j<q;j++)
{

    for(k=qv[j][0];k<qv[j][0]+qv[j][1];k++)
    {
        q1[fl++]=str[k];

    }
    q1[fl]='\0';
    strcpy(q2,q1);
//puts(q1);
//printf("\n%d",fl);

int fl2=0;int count=0;
for(k=0;k<n;k++)
{
    if(str[k]==q1[fl2])
    {
        while(fl2<fl&&str[k++]==q1[fl2++]);
        if(fl2==fl)count++;
        fl2=0;
        k--;
        printf("%d\n",count);
    }

    }

fl=0;
}
}
return 0;
}
