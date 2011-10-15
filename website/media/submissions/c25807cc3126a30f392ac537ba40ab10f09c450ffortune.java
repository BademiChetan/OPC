import java.util.Scanner;
import java.lang.System;
class Main
{
 public static void main(String []args)
  {
    int N[],K[],X,temp,res;

     Scanner p=new Scanner(System.in);
     int T=p.nextInt(),M;
      N=new int[T];
      K=new int[T];
      
      for(M=0;M<T;M++)
       {
        N[M]=p.nextInt();
        K[M]=p.nextInt();
        }
       for(M=0;M<T;M++)
        { 
         temp=N[M]%K[M];
	 for(res=2,X=0;X<temp;X++)
         res=res*res; 
         System.out.println(res);  
        }
   }
}
     
          