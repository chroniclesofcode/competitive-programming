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
#define arr array<LL,2>
const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

LL n;
vector<LL> adj[MX];
unordered_multiset<LL> s[MX];
bool vis[MX];
/*

*/

void solve() {
    cin >> n;
    LL x, y;
    for (LL i = 0; i < n-1; i++) {
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    s[0].insert(0);
    LL cr = 0;
    LL lvl = 1;
    for (LL i = 0; i < n; i++) {
        cin >> x;
        x--;
        if (vis[x]) {
            cout << "No\n";
            return;
        }
        vis[x] = true;
        // Check if should be here
        auto it = s[cr].find(x);
        if (it == s[cr].end()) {
            if (!s[cr].empty()) {
                cout << "No\n";
                return;
            }
            cr++;
            auto it2 = s[cr].find(x);
            if (it2 == s[cr].end()) {
                cout << "No\n";
                return;
            }
            s[cr].erase(it2);
        } else {
            s[cr].erase(it);
        }
        bool flag = false;
        for (auto v : adj[x]) {
            if (!vis[v]) {
                s[lvl].insert(v);
                flag = true;
            }
        }
        if (flag) lvl++;
    }
    cout << "Yes\n";
}





