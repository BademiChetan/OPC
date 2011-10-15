#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int arr[50002];
int arr1[50002];
void Compute(char *str)
{
	int m= strlen(str);
	arr[1]=0;
	int k=0;
	int q;
	for(q=2;q<=m;q++)	
	{
		while(k>0 && str[k]!=str[q-1])
		{
			k=arr[k];
		}
		if(str[k]==str[q-1])
		{
			k=k+1;
		}
		arr[q]=k;
	}
}
int possible(char *t,char *p)
{
	int n=strlen(t);
	int m=strlen(p);
	int q=0;
	int i;	
	int count=0;
	for(i=1;i<=n;i++)
	{
		while(q>0 && p[q]!=t[i-1])
		{
			q=arr1[q];
		}
		if(p[q]==t[i-1])
		{
			q=q+1;
		}
		if(q==m)
		{
			count++;
			q=arr1[q];
		}
	}
	return count;
}
		
int main()
{
	char str[50002];
        char cpy[50002];
        int i;
        char ch;
        int t,n,q,m,k;
 	scanf("%d",&t);
	while(t--)
      {
              scanf("%d\n",&n);
              ch=getchar();
                i=0;
              while(i<n)
              {
                      str[i]=ch;
                      i++;
                      ch=getchar();
              }
	      str[i]='\0';
              scanf("%d",&q);
	      Compute(str);
              while(q--)
                {
                      scanf("%d %d",&m,&k);
                      strcpy(cpy,&str[m]);
                      cpy[k]='\0';
		      for(i=1;i<=k;i++)
			{
				arr1[i]=arr[m+i-1]-arr[m];
			}
		      printf("%d\n",possible(str,cpy));
                }
      }

        return 0;
}

