//TENSOR
#include <iostream>
#include<stdio.h>
using namespace std;
int main(int argc, char **argv)
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int q[4][4]={0,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0};
    int t;
    scanf("%d",&t);
    while(t--){
        int n,odds=0,evens=0,t1;
        scanf("%d",&n);
        while(n--){
            scanf("%d",&t1);
            if(t1&1){
                odds++;
            }else{
                evens++;
            }
        }
        printf(q[evens%4][odds%4]?"WIN\n":"LOSE\n");
    }
	return 0;
}

