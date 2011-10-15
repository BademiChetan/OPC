import java.util.Scanner;


class fortune
{
public static void main(String args[])
{


Scanner sc=new Scanner(System.in);


int t=sc.nextInt();




int i=0;


while(t!=0)
{

double n=sc.nextDouble();

double k=sc.nextDouble();

if(k%2!=0)
{



double chk=Math.pow(2.0,n+2);



chk=chk%k;

System.out.println((int)chk);

}



t--;
}

}

}
