class Solution {
public:
    using ll = long long;
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        int big = *max_element(nums1.begin(), nums1.end());
        unordered_map<ll, ll> mp;
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            if (nums2[i]*(ll)k <= big) {
                mp[nums2[i]*(ll)k]++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j*j <= nums1[i]; j++) {
                if (nums1[i] % j == 0) {
                    if (nums1[i] / j == j) ans += mp[j];
                    else
                        ans += mp[j] + mp[nums1[i]/j];
                }
            }
        }
        return ans;
    }
};
