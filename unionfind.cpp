#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = LLONG_MAX / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;


struct Uf {
    vector<int> grp, sz;

    Uf(int n = MX) {
        grp = vector<int>(n);
        sz = vector<int>(n, 1);
        for (int i = 0; i < n; i++) grp[i] = i;
    }

    int Find(int a) {
        return a == grp[a] ? a : grp[a] = Find(grp[a]);
    }

    void Union(int a, int b) {
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
};

int n, m, k;

void solve() {
    cin >> n;
}
/*

*/







