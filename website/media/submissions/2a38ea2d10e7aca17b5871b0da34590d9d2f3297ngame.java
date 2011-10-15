import java.io.*;

class Main{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        for(int i=0;i<t;i++)
        {
            int n=Integer.parseInt(br.readLine());
            int a[]=new int[100];
            for(int j=0;j<n;j++)
            {
                a[j]=Integer.parseInt(br.readLine());
            }
            for(int j=1;j<=n;j++)
            {
                if(j==n)
                {
                    if(a[j]%2==0)
                    {
                        System.out.println("LOSE");
                    }
                    else
                    {
                        System.out.println("WIN");
                    }
                }
                else
                {
                    int temp=a[j]+a[j+1]-j;
                    a[j+1]=temp;
                }
            }
        }
    }
}