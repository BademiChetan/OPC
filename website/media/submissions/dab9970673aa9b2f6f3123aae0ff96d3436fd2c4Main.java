import java.util.*;
class Main
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
				res=res^(a%2);
			}
sc.nextLine();
			if(res==1)
				System.out.println("LOSE");
			else
				System.out.println("WIN");
		}
	}
}