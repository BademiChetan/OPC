#include<stdio.h>
main()
{
      int cases;
      int n,i,turns=0;
      int a[101],a1,rep,b;
      scanf("%d",&cases);
      while(cases--)
      {
                    turns=0;
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                    {
                                    scanf("%d",&a[i]);
                    }
                    for(i=0;i<n;i+=2)
                    {
                     a1=a[i];
                     b=a[i+1];
                     turns++;           
                     rep=a1+b-turns;
                     a[i+1]=rep;
                    }
                    printf("%d\n",a[i-1]);
                    if(a[i-1]%2==0)
                                   printf("LOSE\n");
                    else
                        printf("WIN\n");
      }
      return 0;
}                    
                                    
