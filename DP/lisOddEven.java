class lisOddEven {

    static int longestIncreasingOddEvenSubsequence(int[] array) {

        int n = array.length;
        int[] dp = new int[n+1];

        // set all to 1
        for (int i=0; i<n; i++) {
            dp[i] = 1;
        }

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {
                if (array[i] > array[j] && (array[i] + array[j]) % 2 != 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }

        }

        // find max
        int max = -100;

        for(int i = 0; i<n; i++) {
            if (dp[i] > max) {
                max = dp[i];
            }
            System.out.print(dp[i] + ", ");
        }

        System.out.println("");

        return max;

    }

    public static void main(String args[]) {

        int[] array = {1, 2, 4, 3, 5, 6, 8, 9, 12};
        System.out.println(longestIncreasingOddEvenSubsequence(array));

    }

}