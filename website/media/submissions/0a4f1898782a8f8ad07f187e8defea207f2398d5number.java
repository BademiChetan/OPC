import java.lang.*;
import java.io.*;
class number
{
public static void main(String args[])throws IOException
{
int t=0,n,k,temp,mod,res;
String str;
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
System.out.print("Enter no of test cases:");
t=Integer.parseInt(br.readLine());
while(t>=1&&t<=10)
{
BufferedReader br1=new BufferedReader(new InputStreamReader(System.in));
System.out.print("Enter string:");
str=br.readLine();
temp=str.indexOf(" ",0);
n=Integer.parseInt(str.substring(0,temp));
k=Integer.parseInt(str.substring(temp+1,str.length()));
mod=n%k;
res=1;
for(int i=1;i<=mod;i++)
{
res=res*4;
}
t--;
System.out.println(res);
}
}
}	