package game;

import java.util.Scanner;

public class NumberGame {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(;T>0;T--)
		{
			int N = sc.nextInt();
			int[] A = new int[N];
			int i;
			for(i=0;i<N;i++)
				A[i] = sc.nextInt();
			int times = N / 2, round=0;
			i=0;
			while(times!=0)
			{
				round++;
				if((A[i]+A[i+1]-round) % 2 == 0)
					System.out.println("LOSE");
				else
					System.out.println("WIN");
				times--;
			}
				
		}
	}
}
