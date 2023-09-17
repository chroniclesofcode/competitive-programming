class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        #define ll long long
        ll n = nums.size();
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i+1;
            ll sum = 0;
            for (int k = 1; k*k*j - 1 < nums.size(); k++) {
                sum += nums[k*k*j-1];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
