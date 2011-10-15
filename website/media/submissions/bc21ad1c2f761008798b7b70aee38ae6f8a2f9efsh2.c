
#include<stdio.h>
int main()
{
    int times;
    scanf("%d",&times);
    int n[times],k,i,j,m,first,second,f;
    char ans[times];
    for(k=0;k<times;k++)
    {
    scanf("%d",&n[k]);
    int a[n[k]];
    int count=0;
    for(m=0;m<n[k];m++)
    {
     scanf("%d",&a[m]);
     count++;
     }
    int t=1,turn=0;
    while(count!=1)
    {
                   int flag=0;
                   if((turn==0 && t%2==1) || (turn==1 && t%2==0) )
                   {
                                        for(m=0;m<count;m++)
                                        {
                                                            first=m;
                                                            for(f=m;f<count;f++)
                                                            {
                                                                                if((a[first]+a[f])%2==0)
                                                                                second=f;
                                                                                flag=1;
                                                                                break;
                                                            }
                                                            if(flag==1)
                                                            break;
                                        }
                                        if(flag==0)
                                        {
                                        first=0;
                                        second=1;
                                        }
                                        a[first]=a[first]+a[second]-t;
                                        for(m=second;m<count;m++)
                                        {
                                                                 a[m]=a[m+1];
                                        }
                                        count--;
                                        t++;
                                        break;
                   }
                   else
                   {
                                        for(m=0;m<count;m++)
                                        {
                                                            first=m;
                                                            
                                                            for(f=m;f<count;f++)
                                                            {
                                                                                if((a[first]+a[f])%2==1)
                                                                                second=f;
                                                                                flag=1;
                                                                                break;
                                                            }
                                                            if(flag==1)
                                                            break;
                                        }
                                        if(flag==0)
                                        {
                                        first=0;
                                        second=1;
                                        }
                                        a[first]=a[first]+a[second]-t;
                                        for(m=second;m<count;m++)
                                        {
                                                                 a[m]=a[m+1];
                                        }
                                        count--;
                                        t++;
                                        break;
                   }
                       
                                                   
    }
    if(a[0]%2==0)
    {
                ans[k]=0;
    }
    else
    {
        ans[k]=1;
    }
    }
    for(k=0;k<times;k++)
    {
                        if(ans[k]==0)
                        printf("win\n");
                        else
                        printf("lose\n");
    
    }
     }
