class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mx = nums[nums.size()-1];
        int mn = nums[0];
        int ans = mx - mn;
        for (int i = 0; i < nums.size()-1; i++) {
            mx = max(mx, nums[i] + 2*k);
            mn = min(nums[0] + 2*k, nums[i+1]);
            ans = min(ans, mx - mn);
        }
        return ans;
    }
};
