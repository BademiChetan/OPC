import java.io.*;
import java.util.*;
class Subset
{
public static void main(String ar[])throws IOException
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int t=Integer.parseInt(br.readLine());
StringTokenizer st;
String s="";
for(int i=1; i<=t; i++)
{
	int m=1;
	st=new StringTokenizer(br.readLine());
	int n=Integer.parseInt(st.nextToken());
	int k=Integer.parseInt(st.nextToken());
	int a[]=new int[n];
	for(int j=0; j<n; j++)
		a[j]=0;
	int p=0;
	while(p!=1)
	{
		int c=0;
		a[c]=a[c]+1;

		while(a[c]!=0)
		{	
			if(a[c]>1)
			{				
				a[c+1]=a[c+1]+1;
				a[c]=0;
			}
			c++;

			if(a[n-1]==2)
			{
				p=1;
				break;
			}
			if((c+1)==n)
			{
				break;
			}

		}

		if(p==1)
			break;

		int sum=0;
		for(int j=0; j<n; j++)
		{
			if(a[j]==1)
			{
				sum=sum+(j+1);
			}
		}
		if(sum%k==0)
			m++;
	}
	s=s+'\n'+m;
}
System.out.println(s);
}
}
	
