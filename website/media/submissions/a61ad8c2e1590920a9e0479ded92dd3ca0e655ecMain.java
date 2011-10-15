
import java.util.Scanner;


class Main {
	public static void main(String[] args)
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner br = new Scanner(System.in);
		int T = br.nextInt();
		for(;T>0;T--){
			int count=0;
			int N = br.nextInt();
			String str = br.next();
			int Q = br.nextInt();
			
			for(;Q>0;Q--){
				int M = br.nextInt();
				int K = br.nextInt();
				String substr = str.substring(M, M+K);
				
				count=0;
				for(int j=0;j<N-K+1;j++){
					if(str.substring(j).startsWith(substr)){
						count++;
					}
				}
				System.out.println(count);
			}

		}
		
	}
}
