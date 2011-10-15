import java.io.*;
import java.util.*;
class Main{
	public static void main(String args[])throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T=Integer.parseInt(br.readLine());
		Map<Integer,Integer> mp=new HashMap<Integer,Integer>(),rev=new HashMap<Integer,Integer>();
		for(int I=0;I<T;I++){
			StringTokenizer st=new StringTokenizer(br.readLine());
			int N=Integer.parseInt(st.nextToken()),K=Integer.parseInt(st.nextToken());
			if(K==1){
				System.out.println(0);
				continue;
			}
			mp.clear();rev.clear();
			
			mp.put(2,0);
			rev.put(0,2);
			int xx,i;
			long val=2;
			for(i=1;i<=N;i++){
				val=(val*val)%K;
				if(!mp.containsKey((int)val)){
					mp.put((int)val,i);
					rev.put(i,(int)val);
				}
				else break;
			}	
			if(i==N+1){
				System.out.println(val);
				continue;
			}
			xx=mp.get((int)val);
			int len=mp.size()-xx;
			N-=xx;
			N%=len;
			if(N==0) N=len;
			System.out.println(rev.get(xx+N-1));
		}
	}
}
