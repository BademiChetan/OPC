#include<iostream>
#define nCr(n, r) (factorial(n) / factorial(n-r) / factorial(r))
#define nPr(n, r) (factorial(n) / factorial(n-r))
using namespace std;
int factorial( int n )
{
    int fact = 1;

    while ( n > 1) {
        fact = fact * n;
        n = n - 1;
    }
    return fact;
}

/*
int factorial(int x) {
 int fac = 1;
 for (int i=2; i<=x; i++) fac *= i;
 return fac;
}
*/
int main(){
	int x,T,C,count;
	cin>>T;
	int store[T][2];
	for(int i=0;i<T;i++){
		cin>>store[i][0]>>store[i][1];
	}
	for(int i=0;i<T;i++){
		count=0;
		/*for(int p=1;p<=store[i][0];p++){
		if(p%store[i][1]==0)
		count++;
		}*/
		x=(store[i][0])/(store[i][1]);
		for(int l=2;l<=store[i][0];l++){
			if(l<=store[i][0]){
				C=(factorial(store[i][0]))/(factorial(store[i][0]-l)*factorial(l));
				for(int k=0;k<=l;k++){
					if((((l-1)*3)+k)%(store[i][1])==0)
						count++;
				}
			}
		}
		cout<<count+x<<endl;
	}
	return 0;
}