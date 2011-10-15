import java.util.*;

class Main
{
	public static void main(String args[])
	{
	Scanner s=new Scanner(System.in);
int p,q,i,j,a,b=0,count=0;

	p=s.nextInt();
	for(i=0;i<p;i++)
	{
	q=s.nextInt();
	count=0;
	b=0;
	a=0;
	for(j=0;j<q;j++)
	{
	if(count<q)
	{
	a=s.nextInt();
	b=b+a-count;
	count++;
	}
	b=a;
	}
	if(b%2==0)
	System.out.println("WIN");
	else
	System.out.println("LOSE");
	}

	}
}