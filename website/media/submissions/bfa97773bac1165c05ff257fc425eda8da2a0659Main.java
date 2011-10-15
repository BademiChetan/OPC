import java.util.Scanner;


class Main {

    static int N;
    public static void main(String[] args) {

        int a,b,t,n;

        Scanner sc= new Scanner(System.in);

        N= sc.nextInt();

        for(int i=0; i<N; i++)
        {
            n= sc.nextInt();
            int A[]= new int[n];
            for(int k=0;k<n;k++)
            {
                A[k]= sc.nextInt();

            }
            a= A[0];

            for(t=1; t<n; t++)
            {

                b= A[t];
                a= a+b-t;

            }
            if(a%2==0)
                System.out.println("LOSE");
            else
                System.out.println("WIN");
        }
        
    }

}
