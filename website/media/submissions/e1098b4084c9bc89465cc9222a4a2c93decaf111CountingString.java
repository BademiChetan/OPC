import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


 class Main {

    public static void main(String[] args)  {
        try{
        int tc,q,m,n,startIndex=0,counter=0,k;
         String str,tempStr,subStr;
         BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
         tc=Integer.parseInt(br.readLine());
         while(tc>0){
            tc--;
            n=Integer.parseInt(br.readLine());
            str=br.readLine();
            str=str.substring(0, n);

              q=Integer.parseInt(br.readLine());
              while(q>0){q--;
                    m=Integer.parseInt(br.readLine());
                    k=Integer.parseInt(br.readLine());
                    startIndex=0;
                    tempStr=str.substring(m,m+k);
                    while(startIndex<n){
                        
                        if(startIndex+k<=n){
                            subStr=str.substring(startIndex,startIndex+k);
                                if(subStr.equals(tempStr))
                                    counter++;
                         }
                        startIndex++;
                    }
                    
                        System.out.println("count="+counter);
                        counter=0;
               }
         }

    }catch(IOException ioe){
        ioe.printStackTrace();
    }catch(Exception e){
        e.printStackTrace();
    }


}//main
}//class
