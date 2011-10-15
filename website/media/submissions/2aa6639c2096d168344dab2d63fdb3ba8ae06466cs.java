import java.util.Scanner;


class s
{


public int count(final String string, final String substring)
  {
     int count = 0;
     int idx = 0;

     while ((idx = string.indexOf(substring, idx)) != -1)
     {
        idx++;
        count++;
     }

     return count;
  }


}



class cs
{
public static void main(String args[])
{


Scanner sc=new Scanner(System.in);


s obj=new s();

int t=sc.nextInt();




while(t!=0)
{

int len=sc.nextInt();
String ss=sc.next();


if(len==ss.length())
{

String s= ss.toLowerCase();

int query=sc.nextInt();

while(query!=0)
{

int m=sc.nextInt();
int k=sc.nextInt();


if((m==0)||(m==1))
m=0;

String chk=s.substring(m,k);

int count =obj.count(s,chk);

System.out.println(count);

query--;
}

}
t--;

}

}

}

