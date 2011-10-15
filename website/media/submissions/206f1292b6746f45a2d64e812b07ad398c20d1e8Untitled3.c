#include<stdio.h>
struct med
{
       long int w,v;
       int f;
       };
       int main()
       {
           int T,ti,N,i,j;
           long int W,av,item;
           scanf("%d",&T);
           int ans[T];
           for(ti=0;ti<T;ti++)
           {
                              scanf("%d %ld",&N,&W);
                              struct med m[N];
                              for(i=0;i<N;i++)
                              scanf("%ld %ld %d",&m[i].w,&m[i].v,&m[i].f);
                              struct med temp;
                              for(i=0;i<N;i++)
                              for(j=i+1;j<N;j++)
                              if(m[i].v<m[j].v)
                              {
                              temp=m[i];
                              m[i]=m[j];
                              m[j]=temp;
                              }
                              av=W;
                              item=0;
                              for(i=0;i<N;i++)
                              {
                              for(j=m[i].f;j*m[i].w>av&&av;j--);
                              av-=j*m[i].w;
                              item+=j*m[i].v;
                              }
                              ans[ti]=item;
                              }
                              for(i=0;i<T;i++)
                              printf("%d",ans[i]);
                              return 0;
                              }
