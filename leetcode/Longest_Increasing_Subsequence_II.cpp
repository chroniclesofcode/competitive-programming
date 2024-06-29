class SegtreePNode {
public:
    using LL = long long;
    LL n = 0;
    
    struct node {
        LL x;
        node() : x{0} {}
        node(int e) : x{e} {}

        friend node operator+(const node &a, const node &b) {
            return node(max(a.x, b.x));
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

class Solution {
public:
    static const int MX = (int)1e5;
    int n;
  
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int big = *max_element(nums.begin(), nums.end());
        SegtreePNode s(big+1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                s.update(1, 1 - s.query(1, 1).x);
                continue;
            }
            int lo = max(1, nums[i] - k);
            int val = s.query(lo, nums[i]-1).x;
            s.update(nums[i], val + 1);
        }
        return s.query(1, big).x;
    }
};
