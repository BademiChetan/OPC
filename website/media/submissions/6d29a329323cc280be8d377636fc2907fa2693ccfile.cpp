#include<iostream>
#include<cmath>

using namespace std;
int main(){
int t ;
scanf("%d",&t);
while(t-- > 0){
	int n , mod;
	scanf("%d %d",&n, &mod);
	long res = 2;
	for(int i = 1; i < n; i++){
	res = (res *  res) % mod;
	}
	int r = res % mod;
	printf("%d\n",r);
	}
return 0;
}