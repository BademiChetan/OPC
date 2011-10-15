import java.io.*;
import java.util.*;

class Main { //Main!!
	
	static final int[][] small;
	
	static {
		small = new int[4][4];
		small[0] = new int[]{0,1,2,3};
		small[1] = new int[]{1,0,3,2};
		small[2] = new int[]{2,3,0,1};
		small[3] = new int[]{3,2,1,0};
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int t = 0; t < T; t++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			if (x < y) {
				int tmp = x;
				x = y;
				y = tmp;
			}
			int r = x/4 - y/4;
			System.out.println(4*r + getSmallRec(x%4,y%4));
		}
	}
	
	static int getSmallRec(int x, int y) {
		return small[x][y];
	}
}
