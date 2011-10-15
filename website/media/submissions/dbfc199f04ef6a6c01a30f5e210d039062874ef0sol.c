#include<stdio.h>
#include<string.h> 
int main()
{
 int i=0,j=0,k=0,count=0,l=0,k1=0,test;
 char a[50000],b[50000];
 gets(a);
 gets(b);
 l=strlen(b);
 while (a[i]!=EOF)
  {
     if (a[i]==b[j])
      {
		printf("%d",i);
        i++;
        j++;
        k1=1;
        if (j==l)
          {
            j=0;
            k=1;
            count=count+1;
          }
     }
    else
     {
       if (k1==1)
          {
           j=0;
           k1=0;
          }
       else
          i++;
    }
 }
 if (k==1)
  {
     printf("\n%d",count);
  }
}
