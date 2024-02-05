class Solution {
public:
    static constexpr int MX = (int)1e5 + 1;
    int INF = (int)1e9 + 10;
    int n, q, t[4*MX], lazy[4*MX];
    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] & t[v*2+1];
        }
    }

    void update(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[v] &= addend;
            lazy[v] &= addend;
        } else {
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), addend);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
            t[v] = t[v*2] & t[v*2+1];
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -1;
        if (l == tl && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return query(v*2, tl, tm, l, min(r, tm)) & 
                query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();
        build(arr, 1, 0, n-1);
        int ans = INT_MAX;
        int lo, hi, mid;
        for (int i = 0; i < n; i++) {
            ans = min(ans, abs(target-arr[i]));
            if (target > arr[i]) {
                continue;
            } else if (target == arr[i]) return 0;
            lo = i+1, hi = n-1;
            while (lo <= hi) {
                mid = lo + (hi-lo)/2;
                q = query(1, 0, n-1, i, mid);
                ans = min(ans, abs(target-q));
                if (q > target) {
                    lo = mid+1;
                } else if (q < target) {
                    hi = mid-1;
                } else return 0;
            }
        }
        return ans;
    }
};
