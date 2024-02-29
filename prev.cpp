#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
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
constexpr LL MX = 3 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k, t[4*MX];
vector<int> adj[MX];

vector<LL> a;

void build(vector<LL> &a, LL v, LL tl, LL tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        LL tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

LL query(LL v, LL tl, LL tr, LL l, LL r) {
    if (l > r) 
        return INF;
    if (l == tl && r == tr) {
        return t[v];
    }
    LL tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm)),
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(LL v, LL tl, LL tr, LL pos, LL new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        LL tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

void solve() {
    cin >> n;
    vector<int> jump(n), fall(n), dp(n, INF);
    for (int i = 0; i < n; i++) cin >> jump[i];
    for (int i = 0; i < n; i++) cin >> fall[i];

    for (int i = 0; i < n; i++) {
        // saying, we slide down from i.
        adj[i+fall[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) sort(adj[i].begin(), adj[i].end());
    vector<LL> a(n, INF);
    build(a, 1, 0, n-1);
    for (int i = 0; i < n; i++) {
        if (i - jump[i] < 0) {
            dp[i] = 1;
        } else {
            dp[i] = query(1, 0, n-1, i-jump[i], i) + 1;
        }
        for (auto idx : adj[i]) {
            if (query(1, 0, n-1, idx, idx) > dp[i]) {
                cout << "updating idx: " << idx << " to: " << dp[i] << '\n';
                update(1, 0, n-1, idx, dp[i]);
            }
        }
    }
    for (int i = 0; i < n; i++) cout << dp[i] << ' '; cout << endl;
    if (dp[n-1] >= INF) {
        cout << -1 << '\n';
    } else {
        int res = dp[n-1];
        cout << res << '\n';
        int reach = n-1 - jump[n-1];
        res--;
        for (int i = n-2; i >= 0; i--) {
            if (dp[i] == res) {
                for (auto j : adj[i]) {
                    if (j < reach) continue;
                    cout << j+1 << ' ';
                    res--;
                    reach = i - jump[i];
                    break;
                }
            }
        }
        cout << "0\n";
    }
}

/*
   dp[i] How many moves does it take to reach the top?
   starting from i, at least.
   you can jump up 0..a[i] distance, however, you
   actually need the minimum DP from b[0..a[i]].
   So you are applying b[i] to all the elements from
   i + 0..a[i]. You need to find the minimum from
   a set of numbers.
   So, we could have an array c[i], which stores
   the value of dp[i+a[i]-b[i]]. So then, we can
   just use a segment tree to find the minimum DP
   value.
   However. the difficult is updating. When we 
   update our c[i], how do we update all the values
   which point to our current node as well? So
   beforehand, we need a list of elements which point
   to our current node. And that's the whole solution.
*/



