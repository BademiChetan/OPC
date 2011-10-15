import java.math.BigInteger;
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
		BigInteger modBI = BigInteger.valueOf(mod);

		long value = 2;
		for (long i = 0; i < exp; i++) {
			set.add(value);
			BigInteger newValue = BigInteger.valueOf(value);
			newValue = newValue.multiply(newValue);
			newValue = newValue.mod(modBI);
			long longValue = newValue.longValue();
			if (set.contains(longValue)) {
				break;
			}
			value = longValue;
		}

		long add = exp % set.size();
		for (long i = 0; i < add; i++) {
			BigInteger newValue = BigInteger.valueOf(value);
			newValue = newValue.multiply(newValue);
			newValue = newValue.mod(modBI);
			value = newValue.longValue();
		}

		return value;
	}
}
