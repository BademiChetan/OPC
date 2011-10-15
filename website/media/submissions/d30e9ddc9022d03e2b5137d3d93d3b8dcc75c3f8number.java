import java.io.*;
class number
{
public static void main(String args[])throws IOException
{
int t=0,temp;
long k,res,n,mod;
String str;
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
t=Integer.parseInt(br.readLine());
while(t>=1&&t<=1000)
{
BufferedReader br1=new BufferedReader(new InputStreamReader(System.in));
str=br1.readLine();
temp=str.indexOf(" ",0);
n=Long.parseLong(str.substring(0,temp));
k=Long.parseLong(str.substring(temp+1,str.length()));
mod=n%k;
res=1;
for(int i=1;i<=mod;i++)
{
res=res*4;
}
if(k%2==0||n<1)
res=0;
t--;
System.out.println(res);
}
}
}	