class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int mx = 1e5 + 10;
        int n = nums.size();
        int left[mx];
        int right[mx];
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) {
            left[i] = max(nums[i], left[i-1]);
        }
        for (int i = n-2; i >= 0; i--) {
            right[i] = min(nums[i], right[i+1]);
        }
        for (int i = 0; i < n-1; i++) {
            if (right[i+1] >= left[i]) {
                return i+1;
            }

        }
        return n-1;
    }
};
