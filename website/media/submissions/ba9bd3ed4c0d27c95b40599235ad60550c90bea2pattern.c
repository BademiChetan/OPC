#include<stdio.h>
#include<string.h>

int main()
{
    long n,i,ind,len,k,n1,count,j,l1;
    scanf("%ld",&n);
    long l[n];
    long cou[n][50000];
    for(i=0;i<n;i++)
   {
       scanf("%ld",&n1);
    char str[n1+1];
    char spr[n1+1];
    char try1[n1+1];
       scanf("%s",str);
       //printf("%s",str);
       scanf("%ld",&l[i]);
      // printf("%ld asdas",l);
    for(j=0;j<l[i];j++)
    {    count=0;
         scanf("%ld%ld",&ind,&len);
   // printf("%ld%ld",ind,len);

    for(k=0;k<len;k++)
    spr[k]=str[ind+k];
    spr[k]='\0';
        for(k=0;k<n1;k++)
       {
        for(l1=k;l1<len+k;l1++)
          try1[l1-k]=str[l1];
          try1[l1]='\0';
       if((strcmp(try1,spr))==0)
         count++;
       }
      cou[i][j]=count;

    }
    }
    for(i=0;i<n;i++)
     for(j=0;j<l[i];j++)
     {
         printf("%ld\n",cou[i][j]);
     }
   }
