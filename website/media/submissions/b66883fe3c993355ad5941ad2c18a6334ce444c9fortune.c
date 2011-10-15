#include<stdio.h>
#include<math.h>
main()
{
long long s, n, k,p;
int i,t;
FILE *fp, *fp1;
fp=fopen("test.txt", "r");
fp1=fopen("output.txt", "w");
if(fp== NULL)
{ printf("file does not exist");;
}
else{
fscanf(fp, "%d", &t);
for(i=0;i<t;i++)
{
fscanf(fp, "%lld %lld", &n, &k);
p=pow(2, n);
s=pow(2, p);
s=s%k;
fprintf(fp1, "%lld\n",s);
}
}}
