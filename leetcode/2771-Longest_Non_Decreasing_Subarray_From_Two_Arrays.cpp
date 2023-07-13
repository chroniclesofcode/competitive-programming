class Solution {
public:
    int dp[(int)1e5+1][2];
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        dp[0][0] = 1;
        dp[0][1] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            // have to find previous max of dp[i][val] when numsi is leq than current numsi
            
            // choose from nums1
            if (nums1[i-1] <= nums1[i]) dp[i][0] = max(dp[i][0], dp[i-1][0]+1);
            if (nums2[i-1] <= nums1[i]) dp[i][0] = max(dp[i][0], dp[i-1][1]+1);
            if (nums1[i-1] <= nums2[i]) dp[i][1] = max(dp[i][1], dp[i-1][0]+1);
            if (nums2[i-1] <= nums2[i]) dp[i][1] = max(dp[i][1], dp[i-1][1]+1);
            if (dp[i][0] == 0) dp[i][0] = 1;
            if (dp[i][1] == 0) dp[i][1] = 1;
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
            // choose from nums2
        }
        return ans;
    }
};
