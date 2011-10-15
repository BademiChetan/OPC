
    #include<iostream>
    #include <fstream>
    #include <stdlib.h>
    #define SIZE 3

    using namespace std;

    void show_subset(bool b[], char c[]);
    void rec_iterate(bool b[],int n, int c[]);
    int constant_k;
    int sum=0;
    int number_of_subsets=0;
    int T,N;

    int main()
    {

    ifstream infile;

    cout<<"enter the number of lines(value of 'T'):" ;
    cin>>T;


    for (int loop3=0; loop3<T; loop3++)
    {
    sum=0;
    number_of_subsets=0;
    cout<<"value of N:";
    cin>>N;
    cout<<"value of K";
    cin>>constant_k;
    int *c=new int(N);

    for (int loop1=0; loop1<N; loop1++)
    {
        c[loop1]=loop1+1;
    }
    bool b[SIZE]={0};
    rec_iterate(b,0,c);
    cout<<number_of_subsets;
    free(c);
    }
    }

    void show_subset(bool b[], int c[])
    {
    bool empty = true;
    for(int i = 0; i < SIZE; ++i)
    if(b[i] == 1)
    {
    empty = 0;
    sum=sum+c[i];
    }
    float div_res = sum%constant_k;
    if (div_res==0)
//        {cout<<"sum: "<<sum<<endl;}
        number_of_subsets=number_of_subsets+1;
    }

    void rec_iterate(bool b[],int n, int c[])
    {
    for(int i = 0; i <= 1; ++i)
    {
    b[n] = i;
    if(n < SIZE -1)
    rec_iterate(b, n + 1,c);
    else{
        sum=0;
    show_subset(b, c);}
    }
    }































