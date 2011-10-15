#include<stdio.h>
int main(){
int T,j,k,co=0;
scanf("%d",&T);
while(j--){

int a[100],e[100],o[100],i,n,t=1,n1,c=0,ce=0;

scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);


for(i=0;i<n;i++){
if(a[i]%2==0){
e[ce]=a[i];ce++;}
else
{e[co]=a[i];co++;}
}

for(i=0;i<n;i++){
if(c>=2){++t;c=0;}
if(t%2==0&&c==1)
{
e[1]=e[1]+e[ce];ce--;c++;

}
if(t%2==0&&c==0){

o[1]=o[1]+e[ce];ce--;c++;
}
if(t%2!=0&&c==0){
e[1]=e[1]+e[ce];ce--;c++;
}
if(t%2!=0&&c==1){
o[1]=o[1]+e[ce];ce--;c++;
}
}
}
if(co!=0)
printf("LOSE");
else
printf("WIN");
return(0);
}