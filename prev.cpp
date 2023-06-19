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

const LL MX = 1e6;
//const LL MOD = 1e7;

int n, m;
#define arr array<int,2>
int vis[MX];
vector<arr> adj[MX];
/*

*/

void solve() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({ c, b });
    }


}





