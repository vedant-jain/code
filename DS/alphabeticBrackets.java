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

    static char getInverse(char c) {
        // character = a -> return z
        int ascii = (int) c;
        return (char) (65 + (90-ascii));
    }

    public static void main(String args[]) {

        out = new PrintWriter(System.out);
        FastReader in = new FastReader();

        int testcases = Integer.parseInt(in.nextLine());
        Stack<Character> s = new Stack<Character>();

        while(testcases-->0) {
            String sequence = "";
            sequence = in.nextLine();

            if (sequence.length() % 2 != 0) {
                out.println("Invalid");
                continue;
            }

            for (int i = 0; i<sequence.length(); i++) {
                if(s.empty()) {
                    s.push(sequence.charAt(i));
                }
                else if (getInverse(s.peek()) != sequence.charAt(i) && ((int) sequence.charAt(i) < 78)) {
                    s.push(sequence.charAt(i));
                }
                else {
                    if (getInverse(s.peek()) == sequence.charAt(i))
                        s.pop();
                    else {
                        break;
                    }
                }
            }

            if (s.empty()) {
                out.println("Valid");
            }
            else {
                s = new Stack<Character>();
                out.println("Invalid");
            }

        }

        out.flush();

    }

}