#include<stdio.h>
int main()
{
int T,i, j,N, M, K,Q, out, p ,q;
char s[50000];
scanf ("%d", &T);
for (i=0;i<T;i++)
{
scanf("%d", &N);
scanf ("%s", s);
scanf ("%d", &Q);
for (j=0; j<Q; j++)
{
scanf ("%d %d", &M, &K);
p=0;
q=M;
out=0;
while (s[p]!='\0')
{
if (s[p]== s[q])
{
p++;
q++;
if (q==M+K)
{
out++;
q=M;
continue;
}
}
else 
{
q=M;
p++;}
}
printf ("%d\n", out);
}
}
return 0;
}
	
