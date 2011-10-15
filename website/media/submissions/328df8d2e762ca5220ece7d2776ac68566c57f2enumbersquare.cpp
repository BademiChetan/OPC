#include<iostream>
#include<stdio.h>
using namespace std;

#define LI long int
int CB(LI x)
{
    int C=0;
    while(x){
        C++;
        x=x/2;
    }
    return C;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        LI x,y;
        cin>>x>>y;
        int pos = max(CB(x) , CB(y))-1;
        //cout<<pos<<endl;
        LI start=0,end=(1<<(pos+1));
        while(pos>=0){
                   //cout<<"at pos"<<pos<<" "<<(x&(1<<pos))<<" "<<(1<<pos)<<endl;
            if ((x&(1<<pos))==(1<<pos)){
                //swapped
                //cout<<"swapped"<<"-";
                if((y&(1<<pos))==(1<<pos))
                {
                    //greater                 
                    //cout<<"greater"<<"-";
                    end=(start+end)/2;
                }else {
                    //smaller
                    //cout<<"smaller"<<"-";
                    start = (start+end)/2;
                }
            }else {
                //unswapped    
                //cout<<"unswapped"<<"-";
                if((y&(1<<pos))==(1<<pos))
                {
                    //greater                 
                    //cout<<"greater"<<"-";
                    start=(start+end)/2;
                }else {
                    //smaller
                    //cout<<"smaller"<<"-";
                    end=(start+end)/2;   
                }
            }
            //printf("start:%d, end:%d \n", start, end);
            pos--;
        }
        cout<<start<<endl;;
    }
}
