import java.io.*;
import java.util.*;
class Pro
{
public static void main(String ar[])throws IOException
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	String s="";
int t=Integer.parseInt(br.readLine());
for(int i=1; i<=t; i++)
{

	int n=Integer.parseInt(br.readLine());
	String str=br.readLine();
	int q=Integer.parseInt(br.readLine());
	for(int j=1; j<=q; j++)
	{
		StringTokenizer st=new StringTokenizer(br.readLine());
		int m=Integer.parseInt(st.nextToken());
		int k=Integer.parseInt(st.nextToken());
		String mk=str.substring(m, m+k);
		int c=0;
		for(int x=0; x<=str.length()-k; x++)
		{
			if(mk.equals(str.substring(x, x+k)))
				c++;
		}
		s=s+c+'\n';
	}

}
System.out.println(s);




}}
