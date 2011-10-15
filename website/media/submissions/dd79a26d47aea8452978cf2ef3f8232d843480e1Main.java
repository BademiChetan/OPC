import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long cases = in.nextInt();
		while (cases-- > 0) {
			System.out.println(expFunction(in.nextLong(), in.nextLong()));
		}
	}

	private static long expFunction(long exp, long mod) {
		Set<Long> set = new HashSet<Long>();

		long value = 2;
		for (long i = 0; i < exp; i++) {
			set.add(value);
			long newValue = value * value;
			newValue %= mod;
			if (set.contains(value)) {
				break;
			}
			value = newValue;
		}

		long add = exp % set.size();
		for (long i = 0; i < add; i++) {
			value *= value;
			value %= mod;
		}

		return value;
	}
}
