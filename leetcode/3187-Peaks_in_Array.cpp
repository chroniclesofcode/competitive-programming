class SegtreePNode {
public:
    using LL = long long;
    LL n = 0;
    
    struct node {
        LL ans = 0;
        LL lisp = 0, risp = 0, lval = 0, rval = 0, amt = 0;
        node() : lval(INT_MAX), rval(INT_MAX) {}
        node(int e) {
            ans = 0;
            amt = 1;
            lisp = 1; risp = 1;
            lval = e; rval = e;
        }

        friend node operator+(const node &a, const node &b) {
            node ret;
            ret.ans = a.ans + b.ans;
            ret.amt = a.amt + b.amt;
            ret.lisp = a.lisp;
            ret.risp = b.risp;
            ret.lval = a.lval; ret.rval = b.rval;
            if (a.amt == 1 && a.rval <= b.lval) {
                ret.lisp = 0;
            }
            if (b.amt == 1 && b.lval <= a.rval) {
                ret.risp = 0;
            }
            if (a.risp && a.rval > b.lval) {
                ret.ans++;
                if (b.amt == 1) {
                    ret.risp = 0;
                }
                if (a.amt == 1) {
                    ret.ans--;
                }
            }
            if (b.lisp && b.lval > a.rval) {
                ret.ans++;
                if (a.amt == 1) {
                    ret.lisp = 0;
                }
                if (b.amt == 1) {
                    ret.ans--;
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
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegtreePNode s(n);
        for (int i = 0; i < n; i++) {
            s.update(i, nums[i]);
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 1) {
                int l = queries[i][1], r = queries[i][2];
                int res = s.query(l, r).ans;
                if (l == r) res = 0;
                ans.push_back(res);
            } else if (queries[i][0] == 2) {
                s.update(queries[i][1], queries[i][2]);
                nums[queries[i][1]] = queries[i][2];
            }
        }
        return ans;
    }
};
