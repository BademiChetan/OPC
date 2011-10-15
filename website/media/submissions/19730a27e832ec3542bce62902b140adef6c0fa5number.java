import java.io.*;
class number
{
public static void main(String args[])
{
int t=0,temp,c=0;
long k=0,res,n=0,mod;
String str;
try
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
t=Integer.parseInt(br.readLine());
}
catch(Exception e)
{
c=1;
}
while(t>=1&&t<=1000)
{
try
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
}
catch(Exception e)
{
res=0;
}
if(k%2==0||n<1||c==1)
res=0;
t--;
System.out.println(res);
}
}
}	