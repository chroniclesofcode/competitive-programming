class SegtreePNode {
public:
    using LL = long long;
    LL n = 0;
    
    struct node {
        int x[2][2];
        node() {}
        node(int e) {
            x[0][0] = 0;
            x[1][0] = x[0][1] = 0;
            x[1][1] = e;
        }

        friend node operator+(const node &a, const node &b) {
            node ret(0);
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        if (j == k) continue;
                        for (int l = 0; l < 2; l++) {
                            ret.x[i][l] = max(ret.x[i][l], a.x[i][j]+b.x[k][l]);
                        }
                    }
                }
            }
            return ret;
        }
    };

    vector<node> t;

    SegtreePNode(LL sz) : n(sz), t(4 * sz + 1) {}

    node query(LL l, LL r, LL v = 1, LL tl = 0, LL tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r) 
            return 0;
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
    using ll = long long;
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        ll ans = 0;
        ll md = (int)1e9 + 7; 

        SegtreePNode s(nums.size());
        for (int i = 0; i < n; i++) s.update(i, nums[i]);
        for (auto &qu : queries) {
            int pos = qu[0], x = qu[1];
            s.update(pos, x);
            auto nd = s.query(0, n-1);
            ans += max({ nd.x[0][0], nd.x[0][1], nd.x[1][0], nd.x[1][1] });
            ans %= md;
        }
        return ans;
    }
};
