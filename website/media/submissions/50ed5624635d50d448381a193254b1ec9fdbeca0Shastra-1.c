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
    scanf("%d",&t);
    i=t;
    while(i>0)
    {
             scanf("%d",&x);
             scanf("%d",&y);
             int remx=x%4;
             int quox=x/4;
             int remy=y%4;
             int quoy=y/4;
             int ans1;
             if(quox=quoy)
                          ans1=c[remx][remy];
             else
                          ans1=c[remx][remy]+quox+quoy;
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
    return 0;
}
