import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class Ishant {
	
	public static void main(String[] args){
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        try {
			String s = in.readLine();
			int i = Integer.parseInt(s);
			
			
			
			for(int j=0;j<i;j++){
				in.readLine();
				String temp = in.readLine();
				int queries = Integer.parseInt(in.readLine());
				for(int p=0; p<queries;p++){
				String[] temp2 =(in.readLine()).split(" ");
				int m = Integer.parseInt(temp2[0]);
				int k = Integer.parseInt(temp2[1]);
				String substr = temp.substring(m, m+k);
				int count = 0;
				for(int z = 0; z+ k <= temp.length(); z++){
					if(substr.equals(temp.substring(z, z+k)))
						count++;
				}
				System.out.println(count);
				
				}
			}
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
