class Solution {
public:
    void recurse(vector<int>& nums, vector<int> &tmp, vector<vector<int>>& ret, int count) {
        ret.push_back(tmp);
        for (int i = count; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            recurse(nums, tmp, ret, i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> pog;
        recurse(nums, pog, ret, 0);
        return ret;
    }
};
