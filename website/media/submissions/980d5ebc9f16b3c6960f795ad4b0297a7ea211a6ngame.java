import java.io.*;

class Main{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        int a[][]=new int[100][100];
        int n[]=new int[100];
        for(int i=0;i<t;i++)
        {
            n[i]=Integer.parseInt(br.readLine());
            for(int j=0;j<n[i];j++)
            {
                a[i][j]=br.read();
            }
        }
        for(int i=0;i<t;i++)
        {
            for(int j=1;j<=n[i];j++)
            {
                if(j==n[i])
                {
                    if(a[i][j]%2==0)
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
                    int temp=a[i][j]+a[i][j+1]-j;
                    a[i][j+1]=temp;
                }
            }
        }
    }
}