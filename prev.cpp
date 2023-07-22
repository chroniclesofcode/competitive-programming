class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        const int MX = nums.size()+5;
        int n = nums.size();
        int inc[MX], dec[MX];
        dec[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i-1]) {
                dec[i] = dec[i-1] + 1;
            } else {
                dec[i] = 1;
            }
        }
        inc[n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] <= nums[i+1]) {
                inc[i] = inc[i+1] + 1;
            } else {
                inc[i] = 1;
            }
        }

        vector<int> ans;
        for (int i = k; i < n-k; i++) {
            if (dec[i-1] >= k && inc[i+1] >= k) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
