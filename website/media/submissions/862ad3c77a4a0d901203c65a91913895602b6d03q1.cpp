#include<iostream.h>
#include<conio.h>
int main()
{
    double a,b;
    int l1,t;
    cin>>t;
    for(l1=0;l1<t;l1++)
    {
                       cin>>a;
                       cin>>b;
                       if(a>b)
                       {
                                cout<<((2*(a-1))-(a-b));
                       }
                       else
                       {
                                cout<<((2*(b-1))-(b-a));
                       }
    }
    getch();
    return 0;
}
