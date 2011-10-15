import java.util.Scanner;


class Main {

    
   
    public static void main(String[] args) {

        Scanner sc= new Scanner(System.in);

        int n= sc.nextInt();

        for(int i=0; i<n; i++)
        {
            long N= sc.nextLong(), K= sc.nextInt();
            long sum=2;
          // if (N<60)
            {
                sum= (long) Math.pow(sum,Math.pow(2,N))%K;

            }
           /* else
                sum= (long) Math.pow(sum,Math.pow(2,N))%K;
            for (int j=1;j<=N; j++)
            {
                sum= (sum*sum)%K;
            } */
            System.out.println(sum);
        }
        

       
    }

}
