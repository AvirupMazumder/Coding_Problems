public class Solution {
    
    private int findMinimumCost(int frndCpty, Map<Integer, Integer> costPerFood) {
        //int N = B.size();
        int N = costPerFood.size();
        int[] dp = new int[frndCpty + 1];
        int i = 0;
        Iterator<Map.Entry<Integer, Integer>> itr = costPerFood.entrySet().iterator();
        while(itr.hasNext()) {
            Map.Entry<Integer, Integer> entry = itr.next();
            int foodCpty = entry.getKey();
            int cost = entry.getValue();
            //System.out.println("foodCapacity = " + foodCpty + " Cost = " + cost);
            for(int j = 0; j <= frndCpty; j++) {
                if(i == 0) {
                    if(j < foodCpty) {
                        dp[j] = 0;
                    } else {
                        dp[j] = cost * (j / foodCpty);
                    }
                } else {
                    if(j < foodCpty) {
                        dp[j] = dp[j];
                    } else {
                        if(dp[j] == 0) {
                            dp[j] = cost * (j / foodCpty) + dp[j % foodCpty];
                        } else {
                            int m = j/foodCpty;
                            int val = Integer.MAX_VALUE;
                            for(int k = 1; k <= m; k++) {
                                val = Math.min(val, cost * k + dp[j - foodCpty * k]);
                            }
                            //dp[j] = Math.min(dp[j], cost * (j / foodCpty) + dp[j % foodCpty]);
                            dp[j] = Math.min(dp[j], val);
                        }
                    }
                }
                //System.out.print(dp[i][j]+" ");
            }
            //System.out.println();
            i++;
        }
        //System.out.println("Vaue = " +dp[frndCpty]);
        return dp[frndCpty];
    }
    
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int solve(final List<Integer> A, final List<Integer> B, final List<Integer> C) {
        int cost1 = 0, n = A.size(), m = B.size();
        Map<Integer, Integer> costPerFood = new TreeMap<>();
        for(int i = 0; i < m; i++) {
            if(costPerFood.containsKey(B.get(i))) {
                int val1 = C.get(i);
                int val2 = costPerFood.get(B.get(i));
                costPerFood.put(B.get(i), Math.min(val1, val2));
            } else {
                costPerFood.put(B.get(i), C.get(i));
            }
        }
        for(int i = 0; i < n; i++) {
            int frndCpty = A.get(i);
            cost1 += findMinimumCost(frndCpty, costPerFood);
        }
        return cost1;
    }
}
