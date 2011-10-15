import java.util.Scanner;


class Main {

    
   
    public static void main(String[] args) {

        Scanner sc= new Scanner(System.in);
        
        int p=0, times=1;

        int n= sc.nextInt();

        for(long i=0; i<n; i++)
        {
            p=0;
            long N= sc.nextLong(), K= sc.nextLong();
            long sum=2;
            long A[]= new long[10000000];

        Label:
            for (int j=1;j<=N; j++)
            {
               
                sum= (sum*sum)%K;
                A[p]= sum;
                p++;
                for (int k=0; k<p-1; k++)
                {
                    if (A[k]==sum)
                    {

                        times = j - 1 - k;
                      
                        break Label;
                    }
                }
               
            }
            System.out.println("times="+times);
            sum=2;

             for (int j=1;j<=(N%times)+times; j++)
             {
                 sum= (sum*sum)%K;
             }

             
            System.out.println(sum);
         }

        

       
    }

}

