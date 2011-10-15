
import java.io.*;
import java.util.*;


class Main
{


    public static int countIndex=0,T,L,M,K,Q;
    public static int Count[] = new int[50000];  
    public static String str,search;
        
    
    public static void main(String[] args) throws IOException
  {
                int i,j,m;
                String input;
                      
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
                
                for(i=0;i<T;i++)
                {  
                    L=Integer.parseInt(br.readLine());
                    str = br.readLine();
                    Q= Integer.parseInt(br.readLine());
                    for(j=0;j<Q;j++)
                    {   
                        search=null;
                        input = br.readLine();
                        StringTokenizer st = new StringTokenizer(input);
                        M = Integer.parseInt(st.nextElement().toString());
                        K= Integer.parseInt(st.nextElement().toString());
                        search=str.substring(M,(M+K)); 
                        CountMatch();
                    }
                    
                }
                for(m=0;m<countIndex;m++)
                {   
                    System.out.println(Count[m]);
                }

}
        
        
        
    
    public static void CountMatch() 
    {
      
        String org=str;
        int i,count=0,I=0;
        do { 
                i = org.indexOf(search);
                
                if(i != -1) 
                {
                    org = org.substring(i+1);
                    
                    
                    I=i;
                   
                    count++;
                }
            } while((I<=(str.length()-1))&&(i!=-1));
        Count[countIndex]=count;
        countIndex++; 
        return;
     }

}


