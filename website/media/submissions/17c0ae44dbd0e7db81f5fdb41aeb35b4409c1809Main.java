import java.util.Scanner;
public class Main
{

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str;
		int t=0,len=0;
		Scanner s=new Scanner(System.in);
		t=s.nextInt();
		len=s.nextInt();
		str=s.next();
		int nq=0;
		nq=s.nextInt();
		while(nq-- > 0)
		{
			int m=0,k=0,i=0;
			m=s.nextInt();
			k=s.nextInt();
			String search="";
			for(i=m;i<m+k;i++)
				search+=str.charAt(i);
			//System.out.println(search);
			int result=1;
			
			if (k > 0)
			{  
				  int start = str.indexOf(search);
				  while (start != -1)
				  {
				   result++;
				   start = str.indexOf(search, start+len);
				  }
			}
		   System.out.println(result);
			
			
			
		}
	}

}
