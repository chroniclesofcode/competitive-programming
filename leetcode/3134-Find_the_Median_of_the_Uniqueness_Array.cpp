class Solution {
public:
    vector<int> a;
    int ct[100001];
    int n;
    long long lt(int mid) {
        memset(ct, 0, sizeof(ct));
        int j = 0;
        long long ans = 0;
        int distinct = 0;
        for (int i = 0; i < a.size(); i++) {
            if (++ct[a[i]] == 1) {
                distinct++;
            }
            while (j < i && distinct > mid) {
                if (--ct[a[j]] == 0) {
                    distinct--;
                }
                j++;
            }
            ans += (i-j+1);
        }
        return ans;
    }

    int medianOfUniquenessArray(vector<int>& nums) {
        a = std::move(nums);
        n = a.size();
        long long tot = (long long)n * (n+1) / 2;
        int lo = 1, hi = (int)1e5;
        int ans = INT_MAX;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            long long smaller = lt(mid);
            if (smaller * 2 >= tot) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

