class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int start = 0;
        int idxmin = -1;
        int idxmax = -1;
        bool maxfound = false;
        bool minfound = false;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                start = i+1;
                maxfound = false;
                minfound = false;
            }
            if (nums[i] == minK) {
                minfound = true;
                idxmin = i;
            }
            if (nums[i] == maxK) {
                maxfound = true;
                idxmax = i;
            }
            if (minfound && maxfound) {
                ans += max(0, min(idxmin, idxmax) - start + 1);
            }

        }
        return ans;
    }
};
