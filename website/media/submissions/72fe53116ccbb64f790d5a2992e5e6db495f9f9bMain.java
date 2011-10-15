

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


 class Main {

    public static void main(String[] args) {
        try{
          int tc,n;
          long num=2,k;
          BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
          tc=Integer.parseInt(br.readLine());
          while(tc>0){
            tc--;
            n=Integer.parseInt(br.readLine());
            k=Integer.parseInt(br.readLine());
                    while(n>0){
                    n--;
                    num*=num;
                    }
                if(num<k)
                    System.out.println(num);
                else
                    System.out.println(num%k);
          num=2;
         }
    }catch(IOException ioe){
            System.out.println("error"); 
    }


}//main
}//class

