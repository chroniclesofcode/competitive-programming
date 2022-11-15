#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 3*1e5 + 5;
const LL MOD = 1000000007;

vector<LL> adj[MX];
LL idx[MX], startRange[MX], endRange[MX], dep[MX];
bool used[MX];
LL n, q;
LL totId = 0;
LL lazyadd[4*MX], lazyval[4*MX];

void update(LL uL, LL uR, LL v, LL k, LL x, LL i = 1, LL cL = 0, LL cR = n) {
    if (uL == cL && uR == cR) {
        lazyadd[i] += x + dep[v] * k;
        lazyadd[i] %= MOD;
        lazyval[i] += k;
        lazyval[i] %= MOD;
        return;
    }
    LL mid = (cL + cR) / 2;
    if (uL < mid) update(uL, min(uR, mid), v, k, x, i * 2, cL, mid);
    if (uR > mid) update(max(uL, mid), uR, v, k, x, i * 2 + 1, mid, cR);
}

long long query(LL p, LL i = 1, LL cL = 0, LL cR = n) {
    if (cR - cL == 1) {
    //cout << "la: " << lazyadd[i] << " lv: " << lazyval[i] << " dp: " << dep[p] << endl;
        return lazyadd[i] - lazyval[i] * dep[p];
    }
    LL mid = (cL + cR) / 2;
    long long ans = lazyadd[i] - lazyval[i] * dep[p];
    //cout << "la: " << lazyadd[i] << " lv: " << lazyval[i] << " dep: " << dep[p] << endl;
    if (p < mid) {
        ans += query(p, i * 2, cL, mid);
        ans %= MOD;
    } else {
        ans += query(p, i * 2 + 1, mid, cR);
        ans %= MOD;
    }
    return ans;
}

void compute_ranges(LL v, LL par, LL d) {
    if (used[v]) return;
    used[v] = true;
    idx[v] = startRange[v] = totId++;
    dep[idx[v]] = d;
    for (LL nxt : adj[v]) {
        if (nxt == par) continue;
        compute_ranges(nxt, v, d+1);
    }
    endRange[v] = totId;
}

void debug() {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << startRange[i]+1 << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << endRange[i]+1 << " ";
    }
    cout << endl << endl;
}

/*
    Calculate distance in query, add max dist then just
    subtract
    had bug with modulo
    had bug with array size of lazy
*/

LL rem(LL a, LL b) {
    return (a % b + b) % b;
}

void solve() {
    cin >> n;
    for (LL i = 1; i <= n-1; i++) {
        LL p;
        cin >> p;
        p--;
        adj[p].push_back(i);
    }

    compute_ranges(0, -1, 0);
    //debug();
    cin >> q;
    for (LL i = 0; i < q; i++) {
        LL type;
        cin >> type;
        if (type == 1) {
            LL v, x, k;
            cin >> v >> x >> k;
            v--;
            update(startRange[v], endRange[v], startRange[v], k, x);
        } else if (type == 2) {
            LL v;
            cin >> v;
            v--;
            //cout << rem(query(startRange[v]), 1000000007) << '\n';
            LL ans = query(startRange[v]) % MOD;
            if (ans < 0) ans += MOD;
            cout << ans << '\n';
        }
    }
    
}


/*

   10
    1 2 3 4 4 3 3 6 7
    8
    1 6 13 96
    2 6
    2 9
    1 7 17 66
    2 7
    2 10
    1 5 32 39
    2 5
    1 1 9 5

*/

