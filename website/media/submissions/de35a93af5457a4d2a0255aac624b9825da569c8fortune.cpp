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
int k;
map<int,int> mp;
int power(int n)
{
    if(!n)
    return 1;
    if(mp[n])
    return mp[n];
  if(n%2==0)
    return mp[k]=((power(n/2)%k)*(power(n/2)%k))%k;
  else
    return mp[k]=((2%k)*(power(n/2)%k)*(power(n/2)%k))%k;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        printf("%d\n",power(power(n)));
    }
}
