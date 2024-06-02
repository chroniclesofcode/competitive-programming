class Solution {
public:
    class SegtreePNode {
    public:
        using LL = long long;
        LL n = 0;

        struct node {
            LL x;
            node() : x{-1} {}
            node(int e) : x{e} {}

            friend node operator+(const node &a, const node &b) {
                return node((a.x) & (b.x));
            }
        };

        vector<node> t;

        SegtreePNode(LL sz) : n(sz), t(4 * sz + 1) {}

        node query(LL l, LL r, LL v = 1, LL tl = 0, LL tr = -1) {
            if (tr == -1) tr = n - 1;
            if (l > r) 
                return node();
            if (l == tl && r == tr) {
                return t[v];
            }
            LL tm = (tl + tr) / 2;
            return query(l, min(r, tm), v * 2, tl, tm) +
                   query(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
        }

        void update(LL pos, LL new_val, LL v = 1, LL tl = 0, LL tr = -1) {
            if (tr == -1) tr = n - 1;
            if (tl == tr) {
                t[v] = new_val;
            } else {
                LL tm = (tl + tr) / 2;
                if (pos <= tm)
                    update(pos, new_val, v * 2, tl, tm);
                else
                    update(pos, new_val, v * 2 + 1, tm + 1, tr);
                t[v] = t[v * 2] + t[v * 2 + 1];
            }
        }
    };
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        SegtreePNode s(n);
        for (int i = 0; i < n; i++) s.update(i, nums[i]);
        long long ans = abs(nums[0]-k);
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) return 0;
            int lo = i+1, hi = n-1;
            ans = min(ans, (long long)abs(nums[i]-k));
            while (lo <= hi) {
                int mid = lo + (hi-lo)/2;
                long long q = s.query(i, mid).x;
                ans = min(ans, abs(k-q));
                if (q > k) {
                    lo = mid+1;
                } else if (q < k) {
                    hi = mid-1;
                } else return 0;
                    
            }
        }
        return ans;
    }
};
