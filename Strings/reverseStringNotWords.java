import java.io.*;
import java.util.*;
import java.lang.*;

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
            catch (IOException err) {
                err.printStackTrace();
            }
            return str;
        }
    }

    static String reverseString(String input) {

        StringBuilder inputString = new StringBuilder();
        inputString.append(input);
        StringBuilder reversedString = new StringBuilder();
        int i, temp;

        for (i = inputString.length()-1; i >= 0; i--) {

            while(i != 0 && inputString.charAt(i-1) != '.') {
                i--;
            }
            // append word after i to reversedString
            // i currently has first char of word
            // temp will be last char of previous word
            if (i != 0)
                temp = i-1;
            else 
                temp = i;

            while(inputString.charAt(i) != '\0' && inputString.charAt(i) != '.') {
                reversedString.append(inputString.charAt(i));
                if (i+1 == inputString.length())
                    break;
                i++;
            }
            reversedString.append(".");

            i = temp;
        }

        return reversedString.toString();

    }

    public static void main(String args[]) {
        out = new PrintWriter(System.out);
        FastReader in = new FastReader();

        String inputString = in.nextLine();
        out.println(reverseString(inputString));
        out.flush();
    }

}