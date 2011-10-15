#include<stdio.h>
int main()
{
int T,i, j,N, M, K,Q, out, p ,q;
char s[50000], t[50000];
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
while (p<K)
{
t[p]=s[p+M];
p++;
}
t[p]='\0';
p=0;
q=0;
out=0;
while (s[p]!='\0')
{
if (s[p]== t[q])
{
p++;
q++;
if (t[q]== '\0')
{
out++;
q=0;
continue;
}
}
else 
{
q=0;
p++;}
}
printf ("%d\n", out);
}
}
return 0;
}
	
