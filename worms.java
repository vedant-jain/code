import java.io.*;
import java.util.*;

public class worms {

    public static PrintWriter out;
    static class FastReader{
        BufferedReader br;
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            }
            catch(IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static int binarySearch(int[] labels, int worm) {

        int high = labels.length - 1;
        int low = 0;

        while(low < high) {

            int mid = (low + high + 1) /2;

            if (worm >= labels[mid]) {    
                low = mid;
            }
            else {
                high = mid - 1;
            }

        }

        return low;

    }
    
    public static void main(String[] args) {
        
        out = new PrintWriter(System.out);
        FastReader in = new FastReader();
        
        in.nextLine();

        int[] data = Arrays.stream(in.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        // int worms = Integer.parseInt(in.nextLine());
        in.nextLine();
        int[] worms = Arrays.stream(in.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int[] startingLabels = new int [data.length];
        startingLabels[0] = 1;

        for (int i = 1; i < data.length; i++) {

            startingLabels[i] = startingLabels[i-1] + data[i-1];

        }

        for (int i = 0; i < worms.length; i++) {

            out.println(binarySearch(startingLabels, worms[i]) + 1);

        }

        out.flush();
        
    }
    
}