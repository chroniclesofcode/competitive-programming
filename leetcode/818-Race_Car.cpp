class Solution {
public:
    int racecar(int target) {
        int inf = (int)1e9;
        vector<int> dp(target+1, inf);
        int pp = 0;
        for (int i = 0; i <= target; i++) {
            if (i == (1<<pp)-1) {
                dp[i] = pp;
                ++pp;
                continue;
            }
            int under = (1<<(pp-1))-1;
            int over = (1<<pp)-1;
            for (int j = 0; j < pp; j++) {
                int travel = i - (((1<<(pp-1))-1)-((1<<j)-1));
                dp[i] = min(dp[i], (pp-1)+1+j+1+dp[travel]);
            }
            dp[i] = min(dp[i], pp+dp[over-i]+1);
        }
        return dp[target];
    }
};
