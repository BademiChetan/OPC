using namespace std;

#include<iostream>
#include<fstream>

int T,N,K;

void solve()
{
    int p=1,i,dummy=2;
    for(i=1;(1<<i)<=N;i++)
    {
        dummy=(dummy*dummy)%K;
        //cout<<i<<" "<<(1<<i)<<"\n";
        if((N & (1<<i))>0)
        p=(p*dummy)%K;

    }
    cout<<p<<"\n";
}

void cit()
{
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        N=N*2;
        solve();
    }
}

int main()
{
    cit();
    return 0;
}
