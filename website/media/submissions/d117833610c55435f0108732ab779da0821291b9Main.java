import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		while (cases-- > 0) {
			long n = in.nextLong();
			long k = in.nextLong();
			System.out.println(fastExp(2, fastExp(2, n, k), k));
		}
	}

	private static long fastExp(long base, long exp, long mod) {
		if (exp == 1) {
			return base;
		}

		long half = fastExp(base, exp / 2, mod);
		long res = half * half;
		res %= mod;
		if (exp % 2 == 1) {
			res *= base;
		}
		return res % mod;
	}
}
