/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.*;
/**
 *
 * @author DEVA
 */
class SquaringColor {
    public static void main(String args[])throws Exception
    {
        BufferedReader dis=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(dis.readLine());
        String str="";
        int a[][]=new int[n][2],i,b;
        for(i=0;i<n;i++)
        {
            a[i][0]=Integer.parseInt(dis.readLine());
            a[i][1]=Integer.parseInt(dis.readLine());
            if(a[i][0]>=a[i][1])
            {
                b=(a[i][0]-a[i][1]);
                str=str+"\n"+b;
            }
            else
             {
                b=(a[i][0]-a[i][1]);
                str=str+"\n"+b;
            }
        }
        System.out.println(str);
    }
}
