public class Solution {
    public int solve(String A, String B) {
        int N1 = A.length(), N2 = B.length();
        int[][] dp = new int[N1][N2];
        dp[0][0] = 0;
        for(int i = 0; i < N1; i++) {
            for(int j = 0; j < N2; j++) {
                char ch1 = A.charAt(i);
                char ch2 = B.charAt(j);
                if(i == 0) {
                    if(j == 0) {
                        dp[i][j] = 0;
                        if(ch1 == ch2) {
                            dp[i][j] = 1;
                        }
                    } else {
                        if(ch1 == ch2) {
                            dp[i][j] = 1;
                        } else {
                            dp[i][j] = dp[i][j - 1];
                        }
                    }
                } else {
                    if(j == 0) {
                        dp[i][j] = dp[i - 1][j];
                        if(ch1 == ch2) {
                            dp[i][j] = 1;
                        }
                    }
                    else {
                        if(ch1 == ch2) {
                            dp[i][j] = Math.max(dp[i - 1][j],dp[i - 1][j - 1] + 1);
                        } else {
                            dp[i][j] = Math.max(dp[i - 1][j],dp[i][j - 1]);
                        }
                    }
                }
            }
        }
        return dp[N1 - 1][N2 - 1];
    }
}
