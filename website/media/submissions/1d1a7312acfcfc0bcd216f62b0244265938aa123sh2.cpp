#include<iostream.h>
#include<conio.h>
#include<string.h>
int main()
{
    int times;
    cin>>times;
    int n[times];
    char ans[times][5];
    for(int k=0;k<times;k++)
    {
    cin>>n[k];
    char arr[2*n[k]];
    fflush(stdin);
    gets(arr);
    int a[n[k]];
    int count=0;
    for(int i=0;i<2*n[k];i++)
    {
            if(arr[i]!=' ')
            {
                         a[count]=int(arr[i])-48;
                         count++;
            }
    }
    int t=1;
    while(count!=1)
    {
                   a[0]=a[0]+a[1]-t;
                   for(int i=1;i<count;i++)
                   {
                           a[i]=a[i+1];
                   }
                   count--;
    }
    if(a[0]%2==0)
    strcpy(ans[k],"WIN");
    else
    strcpy(ans[k],"LOSE");
    }
    for(int k=0;k<times;k++)
    {
    puts(ans[k]);
    }
     getch();
     }
