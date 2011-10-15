
#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[100]= {0};
        int even=0,odd=0,number;
        for(int i=0; i<n; i++)
        {
            cin>>number;
            if(number%2==0)
            {
                even++;
            }
            else{odd++;}
        }
        int t=1;
        while(1)
        {
            if(t%2!=0)
            {
                if(odd>=2)
                {
                    odd-=2;
                    t++;
                    continue;
                }
                if(even>=2)
                {
                    even-=2;
                    t++;
                    continue;
                }
                cout<<"LOSE\n";
                break;
            }
            else
            {
                if(odd>=1&&even>=1)
                {
                    odd--;
                    even--;
                    t++;
                    continue;

                }
                cout<<"WIN\n";
                break;
            }
        }


    }
    return 0;
}
