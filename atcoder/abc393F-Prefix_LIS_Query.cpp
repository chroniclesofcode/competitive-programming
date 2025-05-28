#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k, q;

class SegtreePoint {
public:
    LL n = 0;
    vector<LL> t;

    SegtreePoint(LL sz) : n(sz), t(4 * sz + 1) {}

    LL query(LL l, LL r, LL v = 1, LL tl = 0, LL tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        LL tm = (tl + tr) / 2;
        return max(query(l, min(r, tm), v * 2, tl, tm),
               query(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr));
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
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }
};

// Queries R and X, R is the suffix len, Xi is lim
// Find longest strictly increasing subsequence for each query
void solve() {
    cin >> n >> q;
    vector<int> a(n);
    map<int,int> cc;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
        cc[x] = 1;
    }
    
    vector<arr3> queries;
    for (int i = 0; i < q; i++) {
        int r, x;
        cin >> r >> x;
        queries.push_back({r-1, x, i});
        cc[x] = 1;
    }
    int M = cc.size() + 1;
    unordered_map<int,int> id;
    int ctr = 0;
    for (auto& [key, val] : cc) {
        id[key] = ++ctr;
    }
    for(int i = 0; i < n; i++) {
        a[i] = id[a[i]];
    }
    sort(queries.begin(), queries.end());
    vector<int> ans(q);
    SegtreePoint tree(M);
    int j = 0; 
    for (int i = 0; i < n; i++) {
        int elem = a[i];
        int big = tree.query(0, elem-1);
        tree.update(elem, big+1);
        while (j < q && queries[j][0] == i) {
            ans[queries[j][2]] = tree.query(0, id[queries[j][1]]);
            j++;
        }
    }
    
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}

/*
    first, coordinate compress.
    what is the longest incr. subseq which ends at this value?
    create a DP array saying, if we end at this value (with this
    being the max) what is the longest subseq we can achieve? We
    We need a separate DP array of values, which we can use a segment
    tree on. So every time we iterate through, we look for the max len
    subsequence underneath the current value all the way to 0.
    As we are doing this, we actually also solve the queries of up to R!
    We can run a segment tree to find the max len subsq under a certain
    number, you see.
*/