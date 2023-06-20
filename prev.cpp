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
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

#define arr array<LL, 2>

LL sz[MX];
LL grp[MX]; 

LL Find(LL a) {
    if (a == grp[a]) {
        return a;
    }
    return grp[a] = Find(grp[a]);
}

void Union(LL a, LL b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        grp[b] = a;
        sz[a] += sz[b];
    }

}

LL n, m;
vector<arr> edges;
/*

*/

void solve() {
    cin >> n >> m;
    LL a, b;
    for (LL i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        edges.push_back({ a, b });
    }

    for (LL i = 0; i < n; i++) {
        grp[i] = i;
        sz[i] = 1;
    }
    LL numc = n;
    LL maxc = 1;

    for (auto &e : edges) {
        a = Find(e[0]);
        b = Find(e[1]);

        if (a == b) {
            Union(a, b);
            maxc = max(maxc, sz[Find(a)]);
        } else {
            Union(a, b);
            numc--;
            maxc = max(maxc, sz[Find(a)]);
        }
        cout << numc << " " << maxc << '\n';
    }

}





