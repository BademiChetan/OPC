import java.util.*;
class str1
{
	public static void main(String args[])
	{
int a,b,len,q,i,j,p,index,count;
String str,substr;
Scanner s;
try
{
	s=new Scanner(System.in);
	p=s.nextInt();
	for(i=0;i<p;i++)
	{
	len=s.nextInt();
	str=s.next();
	q=s.nextInt();
	for(j=0;j<q;j++)
	{
	try{
	a=s.nextInt();
	b=s.nextInt();
	}
	catch(Exception e)
	{
		a=0;
		b=0;
	}
	substr="";
	substr=str.substring(a,a+b);
	count=0;
	index=0;
	while((index+b)<=len)
	{
	if(str.regionMatches(index,substr,0,b))
	count++;
	index++;
	}
	System.out.println(count);
	}
	}
}
catch(Exception e)
{
System.out.println("0");
}	
	}
}