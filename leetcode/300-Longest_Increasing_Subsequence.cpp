class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sz;
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(sz.begin(), sz.end(), nums[i]);
            if (it == sz.end()) sz.push_back(nums[i]);
            else *it = nums[i];
        }
        return sz.size();
    }
};
