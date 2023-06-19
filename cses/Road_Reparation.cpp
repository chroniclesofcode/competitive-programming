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

#define arr array<LL, 3>

LL sz[MX];
LL group[MX]; 

LL Find(LL a) {
    if (a == group[a]) {
        return a;
    }
    return group[a] = Find(group[a]);
}

void Union(LL a, LL b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        group[b] = a;
        sz[a] += sz[b];
    }

}

LL n, m;
vector<arr> edges;
/*

*/

void solve() {
    cin >> n >> m;
    LL a, b, c;
    for (LL i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        edges.push_back({ c, a, b });
    }

    sort(edges.begin(), edges.end());

    for (LL i = 0; i < n; i++) {
        group[i] = i;
    }
    LL ans = 0;
    for (auto &e : edges) {
        a = e[1];
        b = e[2];
        if (Find(a) != Find(b)) {
            ans += e[0];
            Union(a, b);
        }
    }
    LL val = Find(0);
    for (LL i = 1; i < n; i++) {
        if (Find(i) != val) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << ans << endl;
}





