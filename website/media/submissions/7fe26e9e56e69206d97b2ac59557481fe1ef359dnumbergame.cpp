#include <iostream>
//#include <conio.h>

using namespace std;
int main()
{
    int A[100][100]={0};
    int test,n;
    A[1][1]=-1;
    A[2][0]=1;
    A[0][2]=1;
    int B[101];
    for(int i=0;i<100;i++)
    {
            for(int j=0;j<100;j++)
            {
                    if(i+j>2)
                    {
                    if(A[i-2][j+1]==-1||A[i][j-1]==-1)
                    A[i][j]=1;
                    else
                    A[i][j]=-1;
                    }
            }
    }
    cin>>test;
    while(test-->0)
    {
                   int even=0,odd=0;
                   cin>>n;
                   for(int i=0;i<n;i++)
                   {
                    cin>>B[i];
                    if(B[i]%2==0)
                    even++;
                    else odd++;
                    }
                    if(A[even][odd]==-1)
                    cout<<"LOSE";
                    else
                    cout<<"WIN";
    }
                        
    //getch();
    return 0;
}
    
    
