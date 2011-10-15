#include<stdio.h>
int T;
long long N,K,M,Q;
char s[50005],p[50005];
int marked[26];
void clear(long long  * table,int * present)
{
int i=0;
for(i=0;i<26;i++)
{
table[i]=0;
marked[i]=0;
present[i]=0;
}
}
void fill(long long * table,int temp)
{

int i=0;
for(i=0;i<temp&&marked[i]==0;i++)
table[i]=temp+1;

}
void sunday(char *s , char *p)
{

long long table[26];
int i=0,l,temp;
int n=0,m,y=0;
int present[26];
char diff[26];
clear(table,present);
for(m=0;s[m]!='\0';m++);
/*for(i=0;i<m;i++)
{
if(present[s[i]-97]!=1)
diff[y++]=s[i];
present[s[i]-97]=1;
n++;
}
diff[y]='\0';
*/
for(l=0;p[l]!='\0';l++);
temp=l;
l-=1;

int count = 1;
while(l>=0&&marked[p[l]-97]!=1)
{

if(marked[p[l]-97]!=1)
{
table[p[l]-97]=count;
marked[p[l]-97]=1;
}

count++;
l--;
}
for(i=0;i<26;i++)
{
if(marked[i]!=1)
{
table[i]=temp+1;
marked[i]=1;
}
}
int cnt=0;
i=0;
int j=0;
int dummyi=0,dummyj=0;
while(i<m)
{

dummyj=j=0;
dummyi=i;
while(s[dummyi]==p[dummyj]&&s[dummyi]!='\0'&&s[dummyj]!='\0')

{

dummyj++;
dummyi++;
}

if(p[dummyj]=='\0')
cnt++;
i+=table[s[i+temp]-97];
}

printf("\n%d",cnt);

}
int main()
{
scanf("%d",&T);
int i,j=0;
while(T--)
{
p[0]='\0';
scanf("%lld",&N);
scanf("%s",s);
scanf("%lld",&Q);
while(Q--)
{
p[0]='\0';
j=0;
scanf("%lld %lld",&M,&K);
for(i=M;j<K;i++)
p[j++]=s[i];
p[j]='\0';

sunday(s,p);
}
}
return 0;
}
