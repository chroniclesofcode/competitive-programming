#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<int,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 110;
constexpr int MD = (int)1e9 + 7;

int n, m, k;
unordered_set<int> lang[MX];

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

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        grp[i] = i;
        sz[i] = 1;
    }
    int allzero = 1;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k > 0) allzero = 0;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            lang[i].insert(x);
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto l : lang[i]) {
            for (int j = 0; j < n; j++) {
                if (i != j && lang[j].count(l)) {
                    Union(i, j);
                }
            }
        }
    }
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(Find(i));
    }
    cout << s.size() - 1 + allzero << '\n';
}

/*

*/



