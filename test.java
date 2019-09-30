import java.io.*;
import java.util.*;

class test {

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
            catch (IOException err) {
                err.printStackTrace();
            }
        }

    }

    public static void main(String args[]) {
        out = new PrintWriter(System.out);
        FastReader in = new FastReader();

        int[] array = Arrays.stream(in.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    } 
}