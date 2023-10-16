class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int small = 0, big = (int)1e9+1;;
        for (int i = 0; i < n; i++) {
            small = min(small, nums[i]);
            big = max(big, nums[i]);
        }
        int lo = small, hi = big;
        int ans = big;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            int ct = 0;
            for (int i = 0; i < n-1; i++) {
                if (nums[i+1]-nums[i] <= mid) {
                    ct++;
                    i++;
                }
            }
            if (ct >= p) {
                hi = mid-1;
                ans = min(ans, mid);
            } else {
                lo = mid+1;
            }
        }
        return ans;
    }
};
