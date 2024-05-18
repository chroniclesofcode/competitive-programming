class Solution {
public:
    int dp[310][310];
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int tmp = 0;

        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                if (i == j) {
                    dp[i][j] = nums[i-1]*nums[i]*nums[i+1];
                    continue;
                }
                int res = 0;
                for (int k = i; k <= j; k++) {
                    int curr = nums[i-1]*nums[k]*nums[j+1];
                    if (k > i) curr += dp[i][k-1];
                    if (k < j) curr += dp[k+1][j];
                    res = max(res, curr);
                }
                dp[i][j] = res;
            }
        }

        return dp[1][n];
    }
};
