#include<stdio.h>
#include<math.h>
main()
{
long long s[1000], n[1000], k[1000],p;
int i,t;
//FILE *fp;// *fp1;
//fp=fopen("test.txt", "r");
//fp1=fopen("output.txt", "w");
//if(fp== NULL)
//{ printf("file does not exist");;
//}
//else{
scanf("%d", &t);
for(i=0;i<t;i++)
{
scanf("%lld %lld", &n[i], &k[i]);
p=pow(2, n[i]);
s[i]=pow(2,p);
s[i]=s[i]%k[i];

}
for(i=0;i<t;i++)
printf("%lld\n", s[i]);
}
