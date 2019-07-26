import java.io.*;
import java.util.*;

public class subarray {

    public static PrintWriter out;
    static class FastReader {

        BufferedReader br;

        FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextLine() {

            String str = "";
            try {
                str = br.readLine();
            }
            catch(IOException err) {
                err.printStackTrace();
            }

            return str;

        }
        
    }

    public static void main(String[] args) {

        out = new PrintWriter(System.out);
        FastReader in = new FastReader();

        int testcases = Integer.parseInt(in.nextLine());

        while(testcases > 0) {

            int[] info = Arrays.stream(in.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

            int[] array = Arrays.stream(in.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

            int end = 1;
            int currentSum = 0;

            for(int start = 0; start<info[0]-1; start++) {

                currentSum = array[start] + array[end];

                while(currentSum < info[1]) {
                    currentSum += array[++end];
                }

                if (currentSum > info[1]) {
                    currentSum -= array[start];
                    start++;
                }

                if (currentSum == info[1]) {
                    out.println(++start + " " + ++end);
                    break;
                }

                start++;

            }

            testcases--;
        }

        out.flush();

    }
}