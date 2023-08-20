class Solution {
public:
    vector<long long> adj[(long long)1e5 + 10];
    int longestEqualSubarray(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        unordered_set<long long> s;
        for (long long i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            adj[nums[i]].push_back(i);
        }
        long long ans = 1;
        for (auto e : s) {
            long long j = 0;
            long long gaps = 0;
            long long len = 1;
            for (long long i = 1; i < adj[e].size(); i++) {
                long long idx = adj[e][i];
                long long prev = adj[e][i-1];
                gaps += idx - prev - 1;
                len++;
                while (gaps > k && j < i) {
                    gaps -= adj[e][j+1] - adj[e][j] - 1;
                    len--;
                    j++;
                }
                ans = max(ans, len);
            }
            
        }
        return ans;
    }
};

