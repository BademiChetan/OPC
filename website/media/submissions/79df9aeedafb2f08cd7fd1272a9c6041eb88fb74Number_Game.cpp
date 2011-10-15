#include<iostream>
using namespace std;

int main()
{
    int test_cases = 0;
    int num = 0;
    int cur_num;
    
    cin>>test_cases;
    while(test_cases)
    {
        cin>>num;
        int i;
        int sum = 0;
        for(i=0;i<num;++i)
        {
            cin>>cur_num;
            sum+=cur_num;
        }
        int t_tot = (num*(num+1))/2;
        
        if((sum-t_tot)%2==0)
            cout<<"LOSE";
        else cout<<"WIN";
    }
}
