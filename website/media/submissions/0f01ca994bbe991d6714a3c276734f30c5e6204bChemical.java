import java.io.*;
import java.util.*;
class Chemical
{
public static void main(String ar[])throws IOException
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int t=Integer.parseInt(br.readLine());
for(int i=1; i<=t; i++)
{
	StringTokenizer st=new StringTokenizer(br.readLine());
	int n=Integer.parseInt(st.nextToken());
	int bgt=Integer.parseInt(st.nextToken());
	int a[][]=new int[n][3];
	for(int j=0; j<n; j++)
	{
		st=new StringTokenizer(br.readLine());
		a[j][0]=Integer.parseInt(st.nextToken());
		a[j][1]=Integer.parseInt(st.nextToken());
		a[j][2]=Integer.parseInt(st.nextToken());
	}
	int max=0;
	for(int x=0; x<=a[0][2]; x++)
	{
	for(int y=0; y<=a[1][2]; y++)
	{
	for(int z=0; z<=a[2][2]; z++)
	{	
		int c=a[0][1]*x+a[1][1]*y+a[2][1]*z;
		int d=a[0][0]*x+a[1][0]*y+a[2][0]*z;
		if(c>=max && d<=bgt)
			max=c;
	}
	}
	}
	System.out.println(max);
}
}
}
