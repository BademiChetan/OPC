
import java.io.File;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main{

	
	int phi(int x) {
		int r=x;
		for(int i=2; i*i<=x; ++i) {
			if (x%i==0) {
				r-=r/i;
				while(x%i==0) x/=i;
			}
		}
		if (x>1) r-=r/x;
		return r;
	}
	
	BigInteger solve(int n, int k) {
		BigInteger res=BigInteger.ZERO;
		for(int i=1; i*i<=k; ++i) {
			if (n%i==0) {
				if (i%2!=0) {
					BigInteger r=BigInteger.valueOf(2).pow(n/i).multiply(BigInteger.valueOf(phi(i)));
					res=res.add(r);
				} 
				if(i!=k/i && ((k/i)%2!=0)) {
					BigInteger r=BigInteger.valueOf(2).pow(n/(k/i)).multiply(BigInteger.valueOf(phi(k/i)));
					res=res.add(r);
				}
			}
		}
		return res.divide(BigInteger.valueOf(k));
		
	}
		
	void solve() throws Exception {
		//Scanner sc = new Scanner(new File("input.txt"));
		//PrintStream ps = new PrintStream(new File("output.txt"));
		Scanner sc = new Scanner(System.in); 
		PrintStream ps=System.out;
		int tc = sc.nextInt();
		while(tc-->0) {
			int n=sc.nextInt();
			int m=sc.nextInt();
			ps.printf("%s\n",solve(n,m).toString());
		}
	}
	
	public static void main(String[] args) throws Exception {
		new Main().solve();
	}
}
