import java.util.Scanner;


class Main {

    
   
    public static void main(String[] args) {

        Scanner sc= new Scanner(System.in);

        int n= sc.nextInt();

        for(int i=0; i<n; i++)
        {
            int N= sc.nextInt(), K= sc.nextInt();
            long sum=2;
            for (int j=1;j<=N; j++)
            {
                sum= (sum*sum)%K;
            }
            System.out.println(sum);
        }
        

       
    }

}
