class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        #define ll long long
        ll ans = 0;
        ll n = nums.size();
        vector<ll> left(n, -INT_MAX);
        vector<ll> right(n, -INT_MAX);
        ll m = -INT_MAX;
        for (int i = 0; i < n; i++) {
            m = max(m, (ll)nums[i]);
            left[i] = m;
        }
        m = -INT_MAX;
        for (int i = n-1; i >= 0; i--) {
            m = max(m, (ll)nums[i]);
            right[i] = m;
        }
        
        for (int i = 1; i < n-1; i++) {
            ans = max(ans, (left[i-1]-nums[i]) * right[i+1]);
        }
        return ans;
    }
};
