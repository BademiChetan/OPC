#include<stdio.h>

int main()
{
int t,n,a,i,sum,temp;
scanf("%d",&t);
while(t>0) {
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&a);
        sum=sum+a;
    }
    temp=n*(n-1)/2;
    if((sum-temp)%2==0)
        printf("LOSE\n");
    else
        printf("WIN\n");

}
return 0;
}
