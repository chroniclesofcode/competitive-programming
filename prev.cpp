#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<LL,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr LL INF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 1 * 1e5 + 10;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;
LL color[MX];
LL diff[MX];
vector<LL> adj[MX];
unordered_map<LL, unordered_map<LL, LL>> mp;

void solve() {
    cin >> n >> m;
    LL big = 0;
    LL small = INF;
    for (LL i = 1; i <= n; i++) {
        cin >> color[i];
        adj[color[i]].push_back(i);
        big = max(big, color[i]);
        small = min(small, color[i]);
    }
    for (LL i = 0; i < m; i++) {
        LL a, b;
        cin >> a >> b;
        if (color[a] != color[b] && mp[color[a]][color[b]] == 0) {
            diff[color[a]]++;
            diff[color[b]]++;
            mp[color[a]][color[b]] = 1;
            mp[color[b]][color[a]] = 1;
        }
    }
    LL ret = small;
    LL ans = -1;
    for (LL i = small; i <= big; i++) {
        if (diff[i] > ans) {
            ans = diff[i];
            ret = i;
        }
    }
    cout << ret << '\n';
    
}

/*

*/



