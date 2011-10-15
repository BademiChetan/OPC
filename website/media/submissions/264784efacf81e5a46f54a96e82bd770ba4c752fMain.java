import java.io.*;
import java.util.*;

class Main { //Main!!
	
	static int[][] win;
	static int N;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < T; i++) {
			N = Integer.parseInt(in.readLine());
			win = new int[N+1][N+1];
			for (int j = 0; j <=N ; j++) {
				Arrays.fill(win[j], -1);
			}
			int even = 0; int uneven = 0;
			StringTokenizer st = new StringTokenizer(in.readLine());
			for (int j = 0; j < N; j++) {
				int n = Integer.parseInt(st.nextToken());
				if (n % 2 == 0) {
					even++;
				} else {
					uneven++;
				}
			}
			if (isWinning(even, uneven, 1) == 1) {
				System.out.println("WIN");
			} else {
				System.out.println("LOSE");
			}
		}
	}
	
	static int isWinning(int even, int uneven, int t) {
		if (win[even][uneven] != -1) {
			return win[even][uneven];
		}
		if (t % 2 == 1) {
			if (even + uneven == 1) {
				return uneven;
			}
			if (even >= 2) {
				win[even - 2][uneven + 1] = isWinning(even - 2, uneven + 1, t + 1);
				if (win[even - 2][uneven + 1] == 0) {
					return 1;
				}
			}
			if (uneven >= 1) {
				win[even][uneven - 1] = isWinning(even, uneven - 1, t + 1);
				if (win[even][uneven - 1] == 0) {
					return 1;
				}
			}
			return 0;
		} else {
			if (even + uneven == 1) {
				return even;
			}
			if (uneven >= 2) {
				win[even + 1][uneven - 2] = isWinning(even + 1, uneven - 2, t + 1);
				if (win[even + 1][uneven - 2] == 0) {
					return 1;
				}
			}
			if (even >= 1) {
				win[even - 1][uneven] = isWinning(even - 1, uneven, t + 1);
				if (win[even - 1][uneven] == 0) {
					return 1;
				}
			}
			return 0;
		}
	}
}
