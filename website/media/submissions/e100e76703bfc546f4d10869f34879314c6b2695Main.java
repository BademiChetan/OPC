import java.util.*;
 
public class Main
{
 
 
        Scanner scan = new Scanner(System.in);
 
        int arr[] = new int[101];
 
        int banyak;
 
        int turn = 1;
 
        public Main()
        {
                int t = scan.nextInt();
 
                                for(int x=0;x<t;x++)
                                {
 
                                        int z = scan.nextInt();
                                        turn = 1;
                                        banyak = z;
                                        for(int y=0;y<z;y++)
                                        {
                                                arr[y] = scan.nextInt();
                                        }
 
 
                                        while(true)
                                        {
 
                                                int hasil = arr[0] + arr[1] - turn;
 
                                                arr[0] = hasil;
 
                                                if(banyak>0)
                                                {
                                                        for(int beh=1;beh<banyak;beh++)
                                                        arr[beh] = arr[beh+1];
                                                        banyak--;
                                                }
                                                else
                                                {
                                                        break;
                                                }
 
                                                turn++;
                                        }
 
                                        if(arr[0]%2==0)
                                        System.out.println("WIN");
                                        else
                                        System.out.println("LOSE");
                }
 
        }
 
        public static void main(String[] args)
        {
 
 
                new Main();
 
 
        }
 
}