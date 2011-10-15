#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
main()
{
      clock_t start = clock();
      int t,n,q;
      char ch;
      scanf("%d",&t);
      do
      {
      scanf("%d",&n);
      char str[n];
      scanf("%s",&str);
      scanf("%d",&q);
      int num[q][2],ans[q],i,j,count,k;
      for(i=0;i<q;i++)
      scanf("%d%c%d",&num[i][0],&ch,&num[i][1]);
      for(i=0;i<q;i++)
      {   
      int m=0,f=0;
      count=0;
      char temp[num[i][1]],t[num[i][1]];
      for(j=num[i][0];j<(num[i][0]+num[i][1]);j++)
      temp[m++]=str[j];
      temp[m]='\0';
      for(j=0;j<=(n-num[i][1]);j++)
      {
                                  for(k=j;k<(j+num[i][1]);k++)
                                  t[f++]=str[k];
                                  t[f]='\0';
                                  if(strcmp(t,temp)==0)
                                  count++;
                                  f=0;
                                  }
                                  ans[i]=count;
      }
                                for(i=0;i<q;i++)
                                printf("%d\n",ans[i]);
      }while((--t)!=0);
    printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
    system("pause");  
      }
      
      
      
