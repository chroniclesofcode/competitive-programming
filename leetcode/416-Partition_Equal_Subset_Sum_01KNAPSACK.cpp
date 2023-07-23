class Solution {
public:
    int dp[205][30000];
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        sum /= 2;
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        cout << sum << endl;
        //sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (i > 0) dp[i][j] = dp[i-1][j];
                if (i == 0) {
                    dp[i][j] = nums[i] == j;
                } else if (j - nums[i] >= 0) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]];
                } 
                if (j == sum && dp[i][j] == true) {
                    return true;
                }
            }
        }
        return false;
    }
};
