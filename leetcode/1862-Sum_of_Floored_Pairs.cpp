class Solution {
public:
    const int static MX = 250001;
    int freq[MX];
    int pref[MX];
    int sumOfFlooredPairs(vector<int>& nums) {
        int n = nums.size();
        int big = 0;
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            big = max(big, nums[i]);
        }
        vector<int> uq;
        for (int i = 1; i < MX; i++) {
            if (freq[i] > 0) uq.push_back(i);
            pref[i] += pref[i-1] + freq[i];
        }
        #define ll long long
        long long ans = 0;
        for (int i = 0; i < uq.size(); i++) {
            int ct = 0;
            for (int j = 0; j <= big; j += uq[i]) {
                ans += (ll)freq[uq[i]] * ct * ((ll)pref[j+uq[i]-1] - (j > 0 ? pref[j-1] : 0));
                ans %= (int)1e9 + 7;
                ct++;
            }
        }
        return ans;
    }
};
