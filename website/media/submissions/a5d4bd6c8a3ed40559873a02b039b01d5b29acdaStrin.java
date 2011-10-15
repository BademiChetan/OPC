/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

/**
 *
 * @author Administrator
 */
public class Strin {
    public static void main(String a[]) throws IOException
    {
    int t,l,q=0,i,j,k,id=0,z,x;
    int count = 0;
     int idx = 0;

    String str="",str1,str2,str9="";
    int[][] mk=new int[20][20];
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    Scanner in=new Scanner(System.in);
    t=Integer.parseInt(br.readLine());
    for(i=0;i<t;i++)
    {
    l=Integer.parseInt(br.readLine());
    str=br.readLine();
   
    q=Integer.parseInt(br.readLine());
    for(j=0;j<q;j++)
    {       
        mk[j][0]=in.nextInt();
        mk[j][1]=in.nextInt();
        
    }
    }
     for(j=0;j<q;j++)
    {
                str1=str.substring(0, mk[j][1]);
                
    
     
     while ((idx = str.indexOf(str1, idx)) != -1)
     {
        idx++;
        count++;
     }
System.out.println(count);
count=0;
    }
    }
    
}
