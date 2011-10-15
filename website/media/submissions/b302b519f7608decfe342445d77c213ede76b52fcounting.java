import java.io.*;

public class counting
{

	public static void main(String args[]) throws IOException
	{
		int no_test_cases;
		int length;
		int start;
		int num_q;
		int sub_len;
		int lastIndex;
		int count;
		String string;
		String substring;
		String data = null;
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		data = in.readLine(); 
		no_test_cases = Integer.parseInt(data);
		
		while((no_test_cases--)>0)
		{
			data = in.readLine();
			length = Integer.parseInt(data);
			string = new String(in.readLine());	
			data = in.readLine();
			num_q = Integer.parseInt(data);
			while((num_q--) >0)
			{
				data = in.readLine();
				String[] temp= data.split(" ");	
				start = Integer.parseInt(temp[0]);
				sub_len = Integer.parseInt(temp[1]);
				substring = new String(string.substring(start,start+sub_len));
				lastIndex = 0;
				count =0;
				while(lastIndex != -1)
				{
					lastIndex = string.indexOf(substring,lastIndex);
       					if( lastIndex != -1)
       					{
             					count++;
     					}
     					else if(lastIndex == -1)
     						break;
     					lastIndex+=substring.length();

				}
				System.out.println(count);
					
			}
		}
	}
}
			
