import java.util.*;


class FrogJumpDSAMOCK{

    public static boolean canCross(List<Integer> safe, int maxJump, int k) {
        int jumps = 0, last = 0;
        for(int i = 1; i < safe.size(); i++) {
            if(safe.get(i) - safe.get(i - 1) > maxJump) {
                return false;
            }
            if(safe.get(i) - safe.get(last) > maxJump) {
                last = i - 1;
                jumps++;
            }
        }
        jumps++;
        return jumps <= k;
    }
    public static int frogJump(int N , int k , int M , int flawed[]) {
        Set<Integer> flawedSet = new HashSet<>();
        for(int f:flawed)
            flawedSet.add(f);
        List<Integer> safe = new ArrayList<>();
        safe.add(0);
        for(int i = 1; i <= N; i++) {
            if(!flawedSet.contains(i)) {
                safe.add(i);
            }
        }
        safe.add(N + 1);
        int lo = 1, hi = N + 1, ans = hi;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(canCross(safe, mid, k)) {
                ans = mid;
                //System.out.print(ans+" ");
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
        /*
        int m = safe.size();
        int INF = (int)1e9;

        int[][] dp = new int[m][k + 1];
        for(int[] row : dp) 
            Arrays.fill(row, INF);
        dp[0][0] = 0;
        for(int i = 1; i < m; i++) {
            for(int j = 1; j <= k; j++) {
                for(int p = 0; p < i; p++) {
                    if(dp[p][j - 1] != INF) {
                        int jump = safe.get(i) - safe.get(p);
                        dp[i][j] = Math.min(dp[i][j], Math.min(dp[p][j - 1], jump));
                    }
                }
            }
        }
        for(int i = 0; i < dp.length; i++) {
            for(int j = 0; j < dp[0].length; j++) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
        int ans = INF;
        for(int j = 1; j <= k; j++) {
            ans = Math.min(ans, dp[m - 1][j]);
        }
        return (ans == INF ? -1 : ans);*/
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        assert(n <= 500000 && n >= 1);
        int k = scanner.nextInt();
        assert(k <= 500000 && k >= 1);
        int m = scanner.nextInt();
        assert(m <= n && m >= 1);
        int stones[] = new int[m];
        for(int i = 0 ; i < m ; i++) {
            stones[i] = scanner.nextInt();
            assert(stones[i] <= n && stones[i] >= 1);
        }
        int result = frogJump(n , k , m , stones);
        System.out.println(result);
        scanner.close();
    }
}
