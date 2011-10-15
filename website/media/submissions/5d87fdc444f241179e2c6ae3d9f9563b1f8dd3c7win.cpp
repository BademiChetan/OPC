#include<iostream>
using namespace std;
int main()
{
    int n,i=0,unit=2,j,z;
    cin>>n;
    int cal[n][2];
    Hello:                    
             cin>>cal[i][0]>>cal[i][1];
             i++;       
             if(i<n)
             goto Hello;
    for(i=0;i<n;i++)
    {
                             unit=2;            
                    hai:
                    unit=unit*unit;
                    j++;
                    if(j<cal[i][0])
                    goto hai;
                      cout<<unit%cal[i][1];
                    }
        return(0);
              
}
