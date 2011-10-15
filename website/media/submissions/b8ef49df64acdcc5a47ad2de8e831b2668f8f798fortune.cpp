using namespace std;

#include<iostream>
#include<fstream>

long long T,N,K;

void solve()
{
    long long p=1,i,dummy=2,kik=2;
    for(i=1;i<=N;i*=2)
    {


        //cout<<i<<" "<<kik<<"\n";
        if(N & i)
        p=(p*dummy)%K;
        dummy=(dummy*dummy)%K;


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
