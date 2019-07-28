class LIS {

    static int longestIncreasingSubsequence(int array[]) {
        int n = array.length;
        int[] dp = new int[n+1];
        // min value is 1 for all
        for (int i = 0; i < n+1; i++) {
            dp[i] = 1;
        }

        for (int i=1; i < n; i++) {
            for(int j=0; j<i; j++) {
                if (array[i] > array[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        int max = -10;
        for (int i = 0; i < n; i++) {
            if (max < dp[i])
                max = dp[i];
        }
        return max;
    }

    public static void main(String argsp[]) {
        int[] array = {10, 22, 9, 33, 21, 50, 41, 60};
        System.out.println("Max: " + longestIncreasingSubsequence(array));
    }

}