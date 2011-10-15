import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		while (cases-- > 0) {
			System.out.println(expFunction(in.nextInt(), in.nextInt()));
		}
	}

	private static int expFunction(int exp, int mod) {
		Set<Integer> set = new HashSet<Integer>();

		int value = 2;
		for (int i = 0; i < exp; i++) {
			set.add(value);
			int newValue = value * value;
			newValue %= mod;
			if (set.contains(value)) {
				break;
			}
			value = newValue;
		}

		int add = exp % set.size();
		for (int i = 0; i < add; i++) {
			value *= value;
			value %= mod;
		}

		return value;
	}
}
