class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[1001][1001];
        // dp[i][j] is longest common subarray ending on i for nums1 and j for nums2.
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] != nums2[j]) {
                    dp[i][j] = 0;
                } else {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};



