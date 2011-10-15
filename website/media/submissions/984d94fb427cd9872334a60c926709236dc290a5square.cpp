#include<iostream>
#include<stdio.h>
using namespace std;
void getmini(int &row,int &col,int row2,int col2)
{
    if(col<4)
    return;
    if(col>=col2/2)
    {
        col-=(col2/2);
        if(row<row2/2)
        row+=row2/2;
        else
        row-=(row2/2);
        getmini(row,col,row2/2,col2/2);
    }
}
int doit(int row,int col,int row2)
{
    //cout<<"i'm in"<<row<< " "<<col<<"\n";
    if(!col)
    return row;
    if(col==1)
    {
        if(row%2==0)
        return row+1;
        return row-1;
    }
    if(row>=row2-2)
        return doit(row-2,col-2,row2);
    else
        return doit(row+2,col-2,row2);
}
int main()
{
    int t;
    scanf("%d",&t);
    int x,y,two=2;
    while(t--)
    {
    scanf("%d %d",&x,&y);
    int tmp=max(x,y);
    while(two<=tmp)
    two*=2;
    getmini(x,y,two,two);
    tmp=max(x,y);
    two=2;
    while(two<=tmp)
    two*=2;
    printf("%d\n",doit(x,y,two));
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<doit(i,j,near(max(i,j)))<<" ";
        cout<<"\n";
    }*/
}
