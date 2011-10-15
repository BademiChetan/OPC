#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<map>
#include<limits.h>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;
#define pb push_back
#define mkpir make_pair
typedef unsigned long long int ull;
typedef long long int ll;
int mod;
map<int,int> mp;
int power(int n)
{
    if(!n)
    return mp[n]=1;
    if(n==1)
    return mp[n]=2;
    if(mp[n])
    return mp[n];
  if(n%2==0)
    return mp[n]=((power(n/2)%mod)*(power(n/2)%mod))%mod;
  else
    return mp[n]=((2%mod)*(power(n/2)%mod)*(power(n/2)%mod))%mod;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&mod);
        printf("%d\n",power(power(n)));
    }
}
