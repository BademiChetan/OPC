import java.util.*;
class lcd
{
	public static void main(String args[])
	{
		int tc,n,a,i,j,res=0;
		Scanner sc=new Scanner(System.in);
		tc=sc.nextInt();sc.nextLine();
		for(i=0;i<tc;i++)
		{
			res=0;
			n=sc.nextInt();sc.nextLine();
			for(j=0;j<n;j++)
			{
				a=sc.nextInt();
				res+=a;
			}
			sc.nextLine();
			n--;
			res=res-((n*(n+1))/2);
			if(res%2==0)
				System.out.println("LOSE");
			else
				System.out.println("WIN");
		}
	}
}