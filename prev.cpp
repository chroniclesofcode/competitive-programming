class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // boils down to find the kth min out of numbers which aren't adjacent.
        int n = nums.size();
        vector<array<int,2>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        int lo = 0;
        int hi = n-1;
        int ans = INT_MAX;
        while (lo <= hi) {
            int ct = 0;
            vector<int> vis(n+1, 0);
            int mid = lo + (hi - lo)/2;
            for (int i = n-1; i >= 0; i--) {
                if (!vis[i+1] && nums[i] <= v[mid][0]) {
                    ct++;
                    vis[i] = 1;
                }
            }
            if (ct >= k) {
                ans = min(ans, v[mid][0]);
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return ans;
    }
};
