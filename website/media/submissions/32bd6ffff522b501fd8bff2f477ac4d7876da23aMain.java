import java.io.*;
import java.util.StringTokenizer;

class Main {

	public int process(int N, int k){
		int num = 2;
		int r = num % k;
		for (int i=0; i<N ;i++)
		{
			num = r*r;
			r = num % 99;
		}
			
		num = num % k;
		return num;
	}	
	
	public static void main(String a[]){

		Main m = new Main();
		String line = "";
		int token1[],token2[];
		try {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		StringTokenizer st;
		int no = Integer.parseInt(br.readLine().trim());
		
		token1 = new int [no];
		token2 = new int [no];

		for (int i = 0;i<no;i++){
			line = br.readLine().trim();
			st = new StringTokenizer(line," ");
			token1[i] = Integer.parseInt(st.nextToken());
			token2[i] = Integer.parseInt(st.nextToken());
		}
		for (int s=0;s<no;s++ )
			System.out.println(m.process(token1[s],token2[s]));
		}
		catch (Exception e) {
			
		}
		
	}
	
}
