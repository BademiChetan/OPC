import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static class Chemical {
        int cost, value, frequency;

        public Chemical(int cost, int value, int frequency) {
            this.cost = cost;
            this.value = value;
            this.frequency = frequency;
        }

        @Override
        public String toString() {
            return "Chemical{" +
                    "cost=" + cost +
                    ", value=" + value +
                    ", frequency=" + frequency +
                    '}';
        }
    }
    public static void main(String[] args)  throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = null;

        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; ++t) {
            st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int budget = Integer.parseInt(st.nextToken());
            Chemical[] chemicals = new Chemical[n];
            for(int i = 0; i < n; ++i) {
                st = new StringTokenizer(in.readLine());
                int c = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int f = Integer.parseInt(st.nextToken());
                chemicals[i] = new Chemical(c, v, f);
            }
            Arrays.sort(chemicals, new Comparator<Chemical>() {
                public int compare(Chemical o1, Chemical o2) {
                    double first = (double) o1.value / o1.cost;
                    double second = (double) o2.value / o2.cost;
                    return new Double(first).compareTo(new Double(second));
                }
            });

            //out.println(Arrays.toString(chemicals));

            int maxValue = 0;
            for(int i = n - 1; i >= 0; --i) {
                int maxChemicals = Math.min(budget / chemicals[i].cost, chemicals[i].frequency);
                budget -= maxChemicals * chemicals[i].cost;
                maxValue += maxChemicals * chemicals[i].value;
            }
            out.println(maxValue);
        }

        in.close();
        out.close();
    }
}
