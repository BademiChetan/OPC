#include <iostream>
#include<cstdio>

using namespace std;
class knap
{
public:
    long long int c,f;
     float v;
};
class div{
public:
 float vc;
int index;
};
void insertion_sort(div x[],int length)

{

int key,i,m;

for(int j=1;j<length;j++)

{

key=x[j].vc;
m=x[j].index;

i=j-1;

while(x[i].vc>key && i>=0)

{

x[i+1].vc=x[i].vc;
x[i+1].index=x[i].index;

i--;

}

x[i+1].vc=key;
x[i+1].index=m;
}

}

int main()
{
    int t,n,i,j;
    long long int w,max;
    knap a[10];
    div v[10];
    scanf("%d",&t);
    while(t--)
    {
        max=0;
     scanf("%d%lld",&n,&w);
     for(i=0;i<n;i++)
     {
     cin>>a[i].c>>a[i].v>>a[i].f;
     v[i].vc=a[i].v/a[i].c;
     v[i].index=i;
     }

insertion_sort(v,n);
for(i=n-1;i>=0;i--)
{
    if(w==0)
    {cout<<max<<"\n";
    break;}
if(w>a[v[i].index].v)
{
    j=w/a[v[i].index].v;
    if(j>a[v[i].index].f)
    j=a[v[i].index].f;
    w=w-j*a[v[i].index].v;
    max=max+j*a[v[i].index].v;
    }
    }
    if(i<0)
cout<<max<<"\n";
    }


    return 0;
}
