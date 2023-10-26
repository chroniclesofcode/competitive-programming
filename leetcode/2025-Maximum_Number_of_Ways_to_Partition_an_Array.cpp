class Solution {
public:
    static const int MX = (int)1e5 + 1;
    long long pref[MX], diff[MX], sol[MX];
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        long long p = 0;
        int nz = 0;
        for (int i = 0; i < n; i++) {
            p += nums[i]; 
            pref[i] = p;
        }
        for (int i = 1; i < n; i++) {
            // diff in partition from 0..i-1 to i..n-1
            diff[i] = pref[i-1] - (pref[n-1] - pref[i-1]);
            if (!diff[i]) nz++;
        }
        unordered_map<long long, long long> m;
        // if changed val in right subarray
        for (int i = 1; i < n; i++) {
            m[diff[i]]++;
            sol[i] += m[k-nums[i]];
        }
        m.clear();
        // if changed val in left subarray
        for (int i = n-1; i >= 1; i--) {
            sol[i] += m[-(k-nums[i])];
            m[diff[i]]++;
        }
        sol[0] += m[-(k-nums[0])];
        //sol[n-1] += m[k-nums[n-1]];
        long long ans = nz;
        for (int i = 0; i < n; i++) ans = max(ans, sol[i]);
        return ans;
    }
};
