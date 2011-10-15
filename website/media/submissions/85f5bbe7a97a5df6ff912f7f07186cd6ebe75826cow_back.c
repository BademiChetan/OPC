#include<stdio.h>
int main()
{
unsigned long long int arr[100000];
unsigned long long int count=0,temp_value,rem,a,b,diff,it,j=1,curr_value=2,k,n;
unsigned int t,i;
int flag=1;
scanf("%d",&t);
for(i=0;i<t;i++){
	scanf("%lld",&n);
	scanf("%lld",&k);
	arr[0]=curr_value;
	while(flag&&j<=n){
        temp_value=curr_value*curr_value;
		curr_value=temp_value%k;
		arr[j]=curr_value;
		if(temp_value>k){
			for(it=0;it<j;it++){
				if(arr[it]==arr[j]){
					a=it;
					b=j;
					flag=0;
					count++;
					break;
				}
			}
		}
        j++;
    }
    if(count!=0){
	diff=b-a;
	rem=(n-(it-2))%diff;
	printf("%lld\n",arr[it+rem]);
    }
    else{
    	printf("%lld\n",arr[n]);
    }
    j=1;
    flag=1;
    curr_value=2;
}
return 0;
}
