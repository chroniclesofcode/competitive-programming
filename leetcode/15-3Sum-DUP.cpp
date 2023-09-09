class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        unordered_map<int, int> m;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            m.clear();
            s.clear();
            for (int j = i+1; j < n; j++) {
                if (s.count(nums[j])) continue;
                if (i != j && m[-nums[i]-nums[j]] > 0 && !s.count(nums[j])) {
                    ans.push_back({nums[i], nums[j], -nums[i]-nums[j]});
                    s.insert(nums[j]);
                }
                if (i != j)
                    m[nums[j]]++;
            }
        }
        return ans;
    }
};
