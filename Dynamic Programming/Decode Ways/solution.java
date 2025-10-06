public class Solution {
    public int numDecodings(String A) {
        int n = A.length();
        int M = 1000000007;
        int[] decodeWays = new int[n + 1];
        for(int i = 0; i <= n; i++) {
            decodeWays[i] = 0;
        }
        decodeWays[0] = 1;
        for(int i = 0; i < n; i++) {
            char ch = A.charAt(i);
            if(i == 0) {
                if(ch != '0') {
                    decodeWays[i + 1] = 1;
                }
            } else {
                if(ch != '0') {
                    decodeWays[i + 1] = decodeWays[i]%M; 
                }
                //String str = A.substring(i - 1,2);
                char ch1 = A.charAt(i - 1);
                if(ch1 != 0 && (ch1 == '1' || (ch1 == '2' && (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch=='6')))) {
                   decodeWays[i + 1] = (decodeWays[i + 1] + decodeWays[i - 1])%M; 
                }
            }
        }
        return decodeWays[n];
    }
        
        
}
