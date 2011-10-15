import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int sum = 0;
		
		int t  = sc.nextInt();
		int i=0, j, n;
		
		while(i<t)
		{
			n = sc.nextInt();
			j=0;
			while(j<n)
			{
				sum+= sc.nextInt();
				j++;
			}
			if(sum%2 == 0)
			{
				System.out.println("WIN");
			}
			else
			{
				System.out.println("LOSE");
			}
			sum = 0;
			i++;
		}
		
	}
}
	