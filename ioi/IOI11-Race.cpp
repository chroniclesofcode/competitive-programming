#include <bits/stdc++.h>
#include "race.h"
 
using namespace std;
 
#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define prLL_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL int
#define arr2 array<LL,2>
#define arr3 array<LL,3>
 
/*
void solve();
MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
 
        solve();
}
*/

constexpr LL INF = (LL)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 2 * 1e5 + 2;
constexpr LL MD = (LL)1e9 + 7;
 
LL n, m, k, sz[MX], rem[MX];
int ct[1000100];
vector<arr2> adj[MX];
LL ans = INF;
LL mdep = 0;
 
LL get_subt(LL u, LL p) {
    sz[u] = 1;
    for (auto &[v, w] : adj[u]) {
        if (v == p || rem[v]) continue;
        sz[u] += get_subt(v, u);
    }
    return sz[u];
}
 
LL centroid(LL u, LL p, LL tot) {
    for (auto &[v, w] : adj[u]) {
        if (v == p || rem[v]) continue;
        if (sz[v] >= tot/2) return centroid(v, u, tot);
    }
    return u;
}


void calc(LL u, LL p, LL dep, LL plen, bool add) {
    if (dep > k) return;
    mdep = max(mdep, dep);
    if (add) {
       if (ct[k-dep] != -1) {
           ans = min(ans, plen + ct[k-dep]);
       }
    } else {
        if (ct[dep] == -1) {
            ct[dep] = plen;
        } else {
            ct[dep] = min(ct[dep], (int)plen);
        }
    }
    for (auto &[v, w] : adj[u]) {
        if (v == p || rem[v]) continue;
        calc(v, u, dep+w, plen+1, add);
    }
}

void resetct(LL u, LL p, LL dep) {
    if (dep > k) return;
    ct[dep] = -1;
    for (auto &[v, w] : adj[u]) {
        if (v == p || rem[v]) continue;
        resetct(v, u, dep+w);
    }
}
 
void centroid_decomp(LL node = 0) {
    LL c = centroid(node, -1, get_subt(node, -1));
    rem[c] = true;
    mdep = 0;
    for (auto &[v, w] : adj[c]) {
        if (rem[v]) continue;
        calc(v, c, w, 1, true);
        calc(v, c, w, 1, false);
    }
    // resetting ct
    for (auto &[v, w] : adj[c]) {
        if (rem[v]) continue;
        resetct(v, c, w);
    }

    for (auto &[v, w] : adj[c]) {
        if (rem[v]) continue;
        centroid_decomp(v);
    }
}

//int htmp[MX][2];
//int ltmp[MX];

int best_path(int N, int K, int H[][2], int L[])
{
    n = N; k = K;
    for (LL i = 0; i < n-1; i++) {
        adj[H[i][0]].push_back({H[i][1], L[i]});
        adj[H[i][1]].push_back({H[i][0], L[i]});
    }
    std::fill(ct, ct + K + 1, -1);
    ct[0] = 0;
    centroid_decomp(0);
    return (ans == INF ? -1 : ans);
}
/*
void solve() {
    cin >> n >> k; 
    for (LL i = 0; i < n-1; i++) {
        int a, b, w; cin >> a >> b >> w;
        htmp[i][0] = a; htmp[i][1] = b;
        ltmp[i] = w;
    }
    cout << best_path(n, k, htmp, ltmp) << '\n';
}
*/
