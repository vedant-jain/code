import java.util.*;
import java.io.*;

class Solution {

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

    static void scrapBook(PrintWriter out, FastReader in, Queue<Integer> q, int loops) {
        int count = 0;
        for (int i = 0; i<loops; i++) {
            String command = in.nextLine();
            if (command.charAt(0) == 'A') {
                if(q.isEmpty()) {
                    out.println(++count);
                }
                else {
                    out.println(q.peek());
                    q.remove();
                    count++;
                }
            }
            else {
                int page = Character.getNumericValue(command.charAt(2));
                if (page <= (count+q.size())) {
                    q.add(page);
                    count--;
                }
            }
        }
        out.println(count);
        out.flush();
    } 

    // 10
    // A
    // R 1
    // A
    // A
    // A
    // R 3
    // R 1
    // R 2
    // A
    // R 3

    public static void main(String args[]) {

        out = new PrintWriter(System.out);
        FastReader in = new FastReader();

        Queue<Integer> queue = new LinkedList<>();

        int loops = Integer.parseInt(in.nextLine());
        scrapBook(out, in, queue, loops);

    }

}