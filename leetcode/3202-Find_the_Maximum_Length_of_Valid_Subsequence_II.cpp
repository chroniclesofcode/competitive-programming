class Solution {
public:
    static const int MX = 1001;
    int dp[MX][MX];
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) dp[i][j] = 1;
            for (int j = 0; j < i; j++) {
                int res = (nums[i]+nums[j])%k;
                dp[i][res] = max(dp[i][res], dp[j][res]+1);
                ans = max(ans, dp[i][res]);
            }
        }
        return ans;
    }
};
