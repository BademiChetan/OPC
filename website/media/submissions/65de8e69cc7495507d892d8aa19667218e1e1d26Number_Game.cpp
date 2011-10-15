#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--){
                   int N;
                   scanf("%d",&N);
                   int arr[N];
                   int sum=0;
                   for(int i=0;i<N;i++){scanf("%d",&arr[i]);sum+=arr[i];}
                   sum+=(N*(N-1))/2;
                   if(sum%2==0) cout<<"LOSE"<<endl;
                   else cout<<"WIN"<<endl;
    }
    return 0;
}
