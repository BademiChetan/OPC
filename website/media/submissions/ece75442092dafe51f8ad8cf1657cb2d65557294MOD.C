#include<stdio.h>
#include<math.h>
int scan()
    {
    unsigned long int acc = 0;
    register char buf;
    buf = getchar();
    while(buf!=10&&buf<='9'&&buf>='0')
    {
    acc = acc * 10 + buf - '0';
    buf = getchar();
    }
    return(acc);
    }
    int main()
    {
	int i,t,c,p;
	long a,b;
	t=scan();
	for(i=0;i<t;i++)
	{
			a=scan();
			p=pow(4,a);
			b=scan();
			c=p%b;
			printf("%d\n",c);
	}
	return 0;
    }