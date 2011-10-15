#include<stdio.h>
struct pro
{
  long int c,v;
  int f;
}a[10],t;
int main()
{
  int te,n,i,j,k;
  long long int w,s;
  scanf("%d",&te);
  while (te--)
    {
      scanf("%d%lld",&n,&w);
      for (i=0;i<n;i++)
	{
	  scanf("%ld%ld%d",&t.c,&t.v,&t.f);
	  for (j=0;j<i && a[j].v<t.v;j++);
	  for (k=j;k<=i;k++)
	    a[k+1]=a[k];
	  a[j]=t;
	}
      for (s=0,i=0;w>0 && i<n;i++)
	{
	  if (w/a[i].c)
	    {
	      if (w/a[i].c < a[i].f)
		{
		  s+=((int)(w/a[i].c))*a[i].v;
		  w-=((int)(w/a[i].c))*a[i].c;
		}
	      else
		{
		  s+=a[i].f*a[i].v;
		  w-=a[i].f*a[i].c;
		}
	    }
	}
      printf("%lld\n",s);
    }
}
