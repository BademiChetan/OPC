//TENSOR
#include <iostream>
#include<stdio.h>
using namespace std;
int main(int argc, char **argv)
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,t1;
        bool nodd,odds=false;
        scanf("%d",&n);
        nodd=((n&3)==1 || (n&3)==2);
        while(n--){
            scanf("%d",&t1);
            odds^=(t1%2);
        }
        printf((nodd^odds)?"WIN\n":"LOSE\n");
    }
	return 0;
}

