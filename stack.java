import java.io.*;
import java.util.*;

public class stack {

    public static PrintWriter out;
    static class FastReader {

        BufferedReader br;
        public FastReader() {
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

        int[] arr = Arrays.stream(in.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        Stack<Integer> stack = new Stack<Integer>();

        int[] answers = new int[arr.length];

        for(int i=arr.length-1; i>=0; i--) {

            // 1 3 2 4
            // 3 4 4 -1

            while((!stack.empty()) && (arr[i] >= stack.peek())) {
                stack.pop();
            } 

            answers[i] = stack.empty() ? -1 : stack.peek();
            stack.push(arr[i]);

        }

        out.println(answers.toString());

        out.flush();

    }

}