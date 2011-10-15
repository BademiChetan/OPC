import java.io.*;
import java.util.StringTokenizer;

class Main {

	public int process(int N, int k){
		int num;
		num = (int)Math.pow(2, Math.pow(2,N));
		num = num % k;
		return num;
	}	
	
	public static void main(String a[]){

		Main m = new Main();
		String line = "";
		int token1,token2;
		int output[];
		try {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		StringTokenizer st;
		int no = Integer.parseInt(br.readLine().trim());
		
		output = new int[no];

		for (int i = 0;i<no;i++){
			line = br.readLine().trim();
			st = new StringTokenizer(line," ");
			token1 = Integer.parseInt(st.nextToken());
			token2 = Integer.parseInt(st.nextToken());
			output[i] = m.process(token1,token2);
		}
		for (int s=0;s<no;s++ )
			System.out.println(output[s]);
		}
		catch (Exception e) {
			
		}
		
	}
	
}
