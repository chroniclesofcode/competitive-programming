class Solution {
public:
    vector<int> left, right;
    int minAbsDifference(vector<int>& nums, int goal) {
        int ans = abs(goal);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n/2; i++) {
            int sz = left.size();
            for (int j = 0; j < sz; j++) {
                left.push_back(left[j] + nums[i]);
            }
            left.push_back(nums[i]);
        }
        for (int i = n/2; i < n; i++) {
            int sz = right.size();
            for (int j = 0; j < sz; j++) {
                right.push_back(right[j] + nums[i]);
            }
            right.push_back(nums[i]);
        }
        left.push_back(0);
        sort(left.begin(), left.end());
        left.erase(unique(left.begin(), left.end()), left.end());
        sort(right.begin(), right.end());
        right.erase(unique(right.begin(), right.end()), right.end());
        for (int i = 0; i < left.size(); i++) {
            int curr = left[i];
            ans = min(ans, abs(curr-goal));
            auto it = lower_bound(right.begin(), right.end(), goal-curr);
            if (it != right.end()) ans = min(ans, abs(goal-(curr+*it)));
            if (it != right.begin()) {
                it--;
                ans = min(ans, abs(goal-(curr+*it)));
            }
        }
        return ans;
    }
};
