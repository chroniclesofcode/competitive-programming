class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> ct;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ct[nums[i]]++;
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        unordered_map<int, int> mp;
        int ans = 0;
        for (auto e : nums) {
            int rt = (int)sqrt(e);
            if (rt * rt != e) {
                ans = max(ans, 1);
                mp[e] = ct[e] > 1 ? 2 : 0;
                continue;
            }
            if (ct[e] == 1) {
                mp[e] = mp[rt] + 1;
                ans = max(ans, mp[e]);
                mp[e] = 0;
            } else if (ct[e] > 1) {
                mp[e] = mp[rt] + 1;
                ans = max(ans, mp[e]);
                mp[e]++;
            }
        }
        ans = max(ans, ct[1] - !(ct[1] % 2));
        return ans;
    }
};
