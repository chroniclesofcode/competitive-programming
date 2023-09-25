class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        #define ll long long
        int n = nums.size();
        ll ans = 0;
        ll mult = 1;
        sort(nums.begin(), nums.end());
        const int md = (int)1e9 + 7;
        for (int i = 0; i < n; i++) {
            ans = (ans + nums[i] * mult) % md;
            mult = (mult * 2) % md;
        }
        mult = 1;
        for (int i = n-1; i >= 0; i--) {
            ans = (ans - nums[i] * mult) % md;
            mult = (mult * 2) % md;
        }
        return (ans < 0 ? ans + md : ans);
    }
};
