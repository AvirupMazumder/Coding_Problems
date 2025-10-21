import java.util.*;
public class Solution {
    public int solve(ArrayList<Integer> A, ArrayList<Integer> B, int C) {
        int M = A.size(), N = B.size();
        int[][] maxProfit = new int[M][C + 1];
        for(int i = 0; i < M; i++) {
            for(int j=0; j <= C; j++) {
                int weight = B.get(i);
                int profit = A.get(i);
                if(j < weight) {
                    if(i == 0) {
                        maxProfit[i][j] = 0;
                    } else {
                        maxProfit[i][j] = maxProfit[i - 1][j];
                    }
                } else {
                    if(i == 0) {
                        maxProfit[i][j] = profit;
                    } else {
                        maxProfit[i][j] = Math.max(maxProfit[i - 1][j], profit + maxProfit[i - 1][j - weight]);
                    }
                }
            }
        }
        return maxProfit[M - 1][C];
    }
}
