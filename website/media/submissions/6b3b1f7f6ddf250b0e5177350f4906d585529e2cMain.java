import java.io.*;
import java.util.StringTokenizer;

class Main {

	public long process(long N, long k){
		
		long num = 2;
		
		num = (long)Math.pow(2, Math.pow(2,N));
		num = num % k;
		return num;
		
	}	
	
	public static void main(String a[]){

		Main m = new Main();
		
		String line = "";
		long token1,token2;
		long output[];
		try {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		StringTokenizer st;
		int no = Integer.parseInt(br.readLine().trim());
		output = new long[no];
		for (int i = 0;i<no;i++){
			line = br.readLine().trim();
			st = new StringTokenizer(line, " ");
			token1 = Long.parseLong(st.nextToken());
			token2 = Long.parseLong(st.nextToken());
			output[i] = m.process(token1,token2);
		}
		for (int s=0;s<no;s++ )
			System.out.println(output[s]);
			
			
		
		}
		catch (Exception e) {
			
		}
		
	}
	
}
