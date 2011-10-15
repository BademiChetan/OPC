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
		Set<BigInteger> set = new HashSet<BigInteger>();
		BigInteger modBI = BigInteger.valueOf(mod);

		BigInteger value = BigInteger.valueOf(2);
		for (long i = 0; i < exp; i++) {
			set.add(value);
			BigInteger newValue = value.multiply(value);
			newValue = newValue.mod(modBI);
			if (set.contains(newValue)) {
				break;
			}
			value = newValue;
		}

		long add = exp % set.size();
		for (long i = 0; i < add; i++) {
			BigInteger newValue = value.multiply(value);
			newValue = newValue.mod(modBI);
			value = newValue;
		}

		return value.longValue();
	}
}
