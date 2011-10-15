import java.io.*;
import java.util.Scanner;
class Main
{
	public static void main(String args[]) throws Exception 
	{
		BufferedReader in=new BufferedReader(new  InputStreamReader(System.in));
		int t=Integer.parseInt(in.readLine());
		int i;
		int[][] var=new int[100][100];
		while((t--)>0)
		{
			int len=Integer.parseInt(in.readLine());
			String sen=in.readLine();
			int q=Integer.parseInt(in.readLine());
			String[] str;
			Scanner scan=new Scanner(System.in);	
			for(i=0;i<q;i++)
			{
				var[i][0]=scan.nextInt();
				//System.out.println("'");
				var[i][1]=scan.nextInt();
				//System.out.println("'");
			}
			for(i=0;i<q;i++)
			{
				String findStr=sen.substring(var[i][0],(var[i][0]+var[i][1]));				
				//System.out.println(findStr);				
				int lastIndex = 0;
				int count =0;
				while(lastIndex != -1)
				{
				       lastIndex = sen.indexOf(findStr,lastIndex);
					//System.out.println(lastIndex);
					       if( lastIndex != -1){
					             count ++;
						lastIndex+=1;
					      				}
					
				}
				System.out.println(count);
			}
		}
	}
}
