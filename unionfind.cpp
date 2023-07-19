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

int n;

/*

*/

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        grp[i] = i;
    }

}





