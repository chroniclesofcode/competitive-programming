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

int sz[MX];
int grp[MX]; 

int Find(int a) {
    if (a == grp[a]) {
        return a;
    }
    return grp[a] = Find(grp[a]);
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

int n, m, k;

void solve() {
    cin >> n;
    vector<array<int,2>> a;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a.push_back({x,y});
        grp[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && (a[j][0] == a[i][0] || a[j][1] == a[i][1])) {
                Union(i, j);
            }
        }
    }
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(Find(i));
    }
    cout << s.size() - 1 << '\n';
}

/*

*/





