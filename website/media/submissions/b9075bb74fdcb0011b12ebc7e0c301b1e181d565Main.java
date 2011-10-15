/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 *
 * @author susheel
 */
 class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String inputStr="";
        int numberOfTests = 0;
        String n="",k="";
        ArrayList<BigInteger> arr = new ArrayList<BigInteger>();
        BigInteger big2 = new BigInteger("2");
        arr.add(big2);
        BigInteger bigOut;

        try
        {
            inputStr = br.readLine();
            numberOfTests = Integer.parseInt(inputStr);
            

               for(int j=0; j<numberOfTests;j++)
              {
                inputStr = br.readLine();
                StringTokenizer st = new StringTokenizer(inputStr, " ");

                if(st.hasMoreTokens())
                {
                    n = st.nextToken();
                    k = st.nextToken();
                    int intn = Integer.parseInt(n);             
                    BigInteger bigK = new BigInteger(k);
                    
                    if(arr.size() > intn)
                    {
                        bigOut = arr.get(intn);
                        bigOut.mod(bigK);
                    }else
                    {
                        int size = arr.size();
                        int iteration = intn - (size-1);
                        BigInteger value = arr.get(size-1);

                        for(int i=0; i<iteration; i++ )
                        {
                            value = value.multiply(value);
                            arr.add(value);
                        }
                        bigOut = arr.get(arr.size()-1);
                        bigOut = bigOut.mod(bigK);
                    }
                    //output = Math.pow(2,n);
                    //output = Math.pow(2,output);

                    System.out.println(bigOut.toString());   
                }
            }
        }catch(Exception e)
        {}


    }

}
