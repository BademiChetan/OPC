#include<stdio.h>
#include<malloc.h>
typedef struct node
{
        int ans;
        struct node *next;
}node;

typedef struct tree
{
        struct node *head;       
}tree;

int main()
{
    tree t1;
    t1.head=NULL; 
    node *latest=NULL;
    int t,x,y,i,j;
    int c[4][4]={(3,2,1,0),(2,3,0,1),(1,0,3,2),(0,1,2,3)};
    c[0][0]=0;
    c[0][1]=1;
    c[0][2]=2;
    c[0][3]=3;
    c[1][0]=1;
    c[1][1]=0;
    c[1][2]=3;
    c[1][3]=2;
    c[2][0]=2;
    c[2][1]=3;
    c[2][2]=0;
    c[2][3]=1;
    c[3][0]=3;
    c[3][1]=2;
    c[3][2]=1;
    c[3][3]=0;
    scanf("%d",&t);
    i=t;
   /* for(i=0;i<20;i++)
    {
                     for(j=0;j<20;j++)
                     {                     
                                       int remx=i%4;
             int quox=i/4;
             int remy=j%4;
             int quoy=j/4;
             int ans1;
             if(quox==quoy)
                          ans1=c[remx][remy];
             else if((quox %2==1 && quoy%2==0) || (quox%2==0) )
                          ans1=(c[remx][remy]+4*(quox+quoy));
             else         
                          ans1=(c[remx][remy]+4*(quox+quoy-2));
                          
             if(ans1/10==0)
             printf("%d  ",ans1);
             else
             printf("%d ",ans1);
                     }
                     printf("\n");
    }
    */while(i>0)
    {
             scanf("%d",&x);
             scanf("%d",&y);
             int remx=x%4;
             int quox=x/4;
             int remy=y%4;
             int quoy=y/4;
             int ans1;
             if(quox==quoy)
                          ans1=c[remx][remy];
             else if((quox %2==1 && quoy%2==0) || (quox%2==0) )
                          ans1=(c[remx][remy]+4*(quox+quoy));
             else         
                          ans1=(c[remx][remy]+4*(quox+quoy-2));
             node *an=(node *)malloc(sizeof(node));
             an->ans=ans1;
             an->next=NULL;
             if(t1.head==NULL)
             {
                       t1.head=an;
                       latest=an;
             }
             else
                       latest->next=an;
                       latest=an;
             i--;       
    }
    latest=t1.head;
    while(latest!=NULL)
    {
                       printf("%d\n",latest->ans);
                       latest=latest->next;
    }
//getch();
return 0;
}
