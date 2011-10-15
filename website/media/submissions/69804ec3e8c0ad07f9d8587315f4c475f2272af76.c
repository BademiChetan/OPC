#include <stdio.h>
#include <string.h>
char buf[50005];
char temp[50005];
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",buf);
        int i;
        scanf("%d",&i);
        while(i--)
        {
            int m,l;
            scanf("%d%d",&m,&l);
            strncpy(temp,buf+m,l);
            temp[l]='\0';
           // printf("%s\n",temp);
            int count=0,pos=0;
            while(pos<n)
            {
                if(strncmp(buf+pos,temp,l)==0){
                count++;
                pos+=l;}
                else
                pos++;
            }
            printf("%d\n",count);               
        }
    }
        return 0;
}
        
