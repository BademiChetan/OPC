#include<iostream>
using namespace std;




/*int first_row(int temp,int x, int y)
{
   if(x==y)
       return a[x][y];
   else
       return temp + a[x][y];

}*/
int main()
{
    long int n,x,y,temp,ans,p;
    long int a[4][4];
    a[0][0] = 0;
    a[0][1] = 1;
    a[0][2] = 2;
    a[0][3] = 3;
    a[1][0] = 1;
    a[1][1] = 0;
    a[1][2] = 3;
    a[1][3] = 2;
    a[2][0] = 2; 
    a[2][1] = 3;
    a[2][2] = 0;
    a[2][3] = 1;
    a[3][0] = 3;
    a[3][1] = 2;
    a[3][2] = 1;
    a[3][3] = 0;	
    cin>>n;
    p = n;
    long int *k = new long int[n];
    int i = 0;
    while(n)
    {
        cin>>x>>y;
        
        /*if(y>x)
        {
            temp = x;
            x = y;
            y = temp;
        }*/
        //cout<<x<<y;
        if(x != y)
        {    
            long int row_m = x%4;
            long int col_m = y%4;
            long int row_d = x/4;
            long int col_d = y/4;
            temp = 4 * row_d + 4 * col_d;
            //ans = first_row(temp,row_m,col_m);
            //cout<<"temp"<<temp<<"\n";
            long int x1 = row_m;
            long int y1 = col_m;
            if(row_d == col_d)
                ans = a[x1][y1];
            else
                ans = temp + a[x1][y1];
        
        }
        else
            ans = 0;
        
        k[i]=ans;
        i++;
        //if(n > 1) 
          //  cout<<ans<<"\n";
        //else
          //  cout<<ans;
        n--;
    }
    for(int i=0;i<p;i++)
    {
        //if(i<p-1)
            cout<<k[i]<<"\n";
        //else
          //  cout<<k[i];

    }
return 0;
}
