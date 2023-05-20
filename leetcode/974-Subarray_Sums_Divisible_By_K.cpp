class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int prefix = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int p = ((prefix % k) + k) % k;
            if (m[p] > 0) {
                ans += m[p];
            }
            m[p]++;
        }
        return ans;

    }
};



