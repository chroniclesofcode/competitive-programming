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
#define NINF -INF
#define arr array<int,2>

const LL MX = 5 * 1e3;
//const LL MOD = 1e7;

int n, adj[MX][MX], in[MX], out[MX];

/*

*/

void solve() {
    cin >> n;
    int a, b;
    vector<arr> rm;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
    }
}
