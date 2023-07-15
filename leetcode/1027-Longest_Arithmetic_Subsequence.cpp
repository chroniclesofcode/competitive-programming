class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<int> m(10001, 0);
        vector<int> d(10001, 0);
        int n = nums.size();
        int ans = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
        }
        for (int i = 0; i <= mx; i++) {
            fill(m.begin(), m.end(), 0);
            fill(d.begin(), d.end(), 0);
            for (int j = 0; j < n; j++) {
                if (nums[j]-i >= 0) {
                    m[nums[j]] = m[nums[j] - i] + 1;
                } else {
                    m[nums[j]] = 1;
                }
                d[nums[j]] = d[nums[j] + i] + 1;
                ans = max(ans, m[nums[j]]);
                ans = max(ans, d[nums[j]]);
            }
        }
        return ans;
    }
};
