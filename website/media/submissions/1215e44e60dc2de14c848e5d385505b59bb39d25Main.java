
import java.io.*;
import java.util.*;


class Main{



    public static int T,N,sum,ans,m;
    public static String Out[] = new String[100];  
    public static String str;
        
    
	public static void main(String[] args) throws IOException
	{
                int i,j,k,l;
                String input;
                      
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
                
                for(i=0;i<T;i++)
                {  
                    ans=0; sum=0;
                    N=Integer.parseInt(br.readLine());
                    str = br.readLine();
                    
                    l=0;
                        StringTokenizer st = new StringTokenizer(str);
                        for(k=0;k<N;k++)
                        {
                            l = Integer.parseInt(st.nextElement().toString());
                            sum=sum+l;
                        }
                        
                        m=(N*(N-1))/2;
                        ans=sum-m;
                       
                        if ((ans%2)==0)
                        { 
                            Out[i]="LOSE";
                        }
                        else
                            { Out[i]="WIN";
                              }
                }
                
                for(i=0;i<T;i++)
                {System.out.println(Out[i]);}
                    
         }
}     