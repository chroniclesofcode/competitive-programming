class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            int lo = i+1, hi = n-1;
            int tot = nums[i];
            while (lo < hi) {
                int tmp = tot + nums[lo] + nums[hi];
                if (tmp == 0) {
                    ans.push_back({nums[lo], nums[i], nums[hi]});
                    int tmpl = lo, tmph = hi;
                    while (lo < i && nums[tmpl] == nums[lo]) lo++;
                    while (hi > i && nums[tmph] == nums[hi]) hi--;
                } else if (tmp >= 0) {
                    hi--;
                } else {
                    lo++;
                }
            }
            while (i+1 < n && nums[i+1] == nums[i]) i++;
        }
        // sort(ans.begin(), ans.end());
        // ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
