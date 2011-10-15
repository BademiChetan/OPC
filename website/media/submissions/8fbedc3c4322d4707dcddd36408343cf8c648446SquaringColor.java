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
        int a[][]=new int[n][2],i;
        for(i=0;i<n;i++)
        {
            a[i][0]=Integer.parseInt(dis.readLine());
            a[i][1]=Integer.parseInt(dis.readLine());
        }
        for(i=0;i<n;i++)
            if(a[i][0]>=a[i][1])
                System.out.println(""+(a[i][0]-a[i][1]));
            else
                System.out.println(""+(a[i][1]-a[i][0]));
    }
}
