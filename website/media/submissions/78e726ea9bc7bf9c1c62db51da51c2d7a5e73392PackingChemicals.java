import java.util.*;
class PackingChemicals
{
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        int i, j, k;
        int T = Integer.parseInt(sc.nextLine());
        for(k=1;k<=T;k++)
        {
        int N = Integer.parseInt(sc.next());
        int W = Integer.parseInt(sc.next());
        double temp, value = 0;
        double [][] list = new double [N][4];
        
        for(i=0;i<list.length;i++)
        {
            for(j=0;j<list[0].length-1;j++)
            {
                list[i][j] = Double.parseDouble(sc.next());
            }
            list[i][3] = list[i][1] / list[i][0];
        }
        
        
        
        for(i=0;i<list.length;i++)
        {
            for(j=i+1;j<list.length;j++)
            {
                if(list[i][3] < list[j][3])
                {
                    temp = list[i][3];
                    list[i][3] = list[j][3];
                    list[j][3] = temp;
                    
                    temp = list[i][2];
                    list[i][2] = list[j][2];
                    list[j][2] = temp;
                    
                    temp = list[i][1];
                    list[i][1] = list[j][1];
                    list[j][1] = temp;
                    
                    temp = list[i][0];
                    list[i][0] = list[j][0];
                    list[j][0] = temp;
                }
            }
        }
        
        for(i=0;i<list.length;i++)
        {
            if(W<=0)
                break;
            value += list[i][1] * list[i][2];
            W -= list[i][0] * list[i][2];
            if(W<=0)
            {
                value -= list[i][3]* Math.abs(W)/list[i][0];
                break;
            }
        }
        
        System.out.println((int)value);
    }
}
}