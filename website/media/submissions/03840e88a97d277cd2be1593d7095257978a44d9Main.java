import java.util.*;

class Main
{

	public static void main(String args[])
	{
	double p;
	int q;
	Scanner s=new Scanner(System.in);
	int k=s.nextInt();
	for(int i=0;i<k;i++)
	{
	p=s.nextInt();
	q=s.nextInt();
	p=p%q;
	p=Math.pow(2,p);
	System.out.println(p);
	}	
	}
}