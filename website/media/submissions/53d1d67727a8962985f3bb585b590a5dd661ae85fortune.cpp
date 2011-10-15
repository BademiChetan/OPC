using namespace std;

#include<iostream>
#include<fstream>

long long T,N,K;

void solve()
{
    long long p=1,i,dummy=2,kik=2;
    for(i=1;kik<=N;i++)
    {
        dummy=(dummy*dummy)%K;

        //cout<<i<<" "<<kik<<"\n";
        if((N & kik)>0)
        p=(p*dummy)%K;
        kik*=2;

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
