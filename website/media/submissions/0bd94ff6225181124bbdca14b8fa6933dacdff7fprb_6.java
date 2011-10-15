import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
class Main{

	public static void main(String args[]) throws IOException{

		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String str,sub;


		int count,strlen,hashSub, M,sublen,Q,T=Integer.parseInt(br.readLine());
//		StringTokenizer strtok;
		String temp;
		while(T-- > 0){
			strlen=Integer.parseInt(br.readLine());
			str=br.readLine();
			Q=Integer.parseInt(br.readLine());
			while(Q-- > 0){
				count=0;
				temp=br.readLine();
				int sp=temp.indexOf(' ');
				M=Integer.parseInt(temp.substring(0,sp));
				sublen=Integer.parseInt(temp.substring(sp+1));
				sub=str.substring(M,M+sublen);
				hashSub=sub.hashCode();
				for(int i=0;i<strlen-sublen+1;i++){
					if(str.substring(i,i+sublen).hashCode()==hashSub)
						count++;
				}
				System.out.println(count);
			}
		}

	}

}