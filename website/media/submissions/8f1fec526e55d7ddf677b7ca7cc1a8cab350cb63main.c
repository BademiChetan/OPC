#include<stdio.h>
#include<string.h>
int main()
{
  int m,k,i,j=0,l,count=0,p,t,q;
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d",&l);
      char str[l],temp[l],temp1[l];
      scanf("%s",str);
      scanf("%d",&q);
      while(q--)
        {
            count = 0;
          scanf("%d %d",&m,&k);
          j=0;
          for(i=m; i<m+k; i++)
            {
              temp[j]=str[i];
              j++;
            }
          temp[j]='\0';

          for(i=0; i<l-k+1; i++)
            {
              j=0;
              for(p=i; p<i+k; p++)
                {
                  temp1[j]=str[p];
                  j++;
                }
              temp1[j]='\0';
              if(strcmp(temp,temp1)==0)
                count++;
            }

          printf("%d\n",count);

        }
    }
return 0;
}
