class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> m;
        int pref = 0;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            ans += m[pref-k];
            m[pref]++;
            //cout << pref << " " << m[pref] << " " << ans << " " << m[pref-k] << endl;
        }
        return ans;
    }
};
