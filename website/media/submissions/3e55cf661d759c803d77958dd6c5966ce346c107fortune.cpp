using namespace std;

#include<iostream>
#include<fstream>

long long T,K;

void solve(long long &N)
{
    long long p=1,i,dummy=2,kik=2;
    for(i=1;i<=N;i*=2)
    {


        //cout<<i<<" "<<kik<<"\n";
        if(N & i)
        p=(p*dummy)%K;
        dummy=(dummy*dummy)%K;


    }
    N=p;

}

void cit()
{
    cin>>T;
    long long N;
    while(T--)
    {
        cin>>N>>K;
        solve(N);
        solve(N);
        cout<<N<<"\n";
    }
}

int main()
{
    cit();
    return 0;
}
