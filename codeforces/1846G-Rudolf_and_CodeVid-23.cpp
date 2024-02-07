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
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 1100;
constexpr int MD = (int)1e9 + 7;

int n, m, k, start, end;
int vis[MX], dist[MX];
vector<arr> adj[MX];
int LG;

void solve() {
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    LG = 1 << n;
    for (int i = 0; i < LG; i++) {
        adj[i].clear();
        dist[i] = (int)1e9 + 69;
    }
    string s; cin >> s;
    int tmp = 0;
    for (int j = 0; j < s.size(); j++) {
        if (s[j] == '1') tmp |= (1 << j);
    }
    start = tmp;

    for (int i = 0; i < m; i++) {
        int d; cin >> d;
        string s1, s2; cin >> s1 >> s2;
        for (int beg = 0; beg < LG; beg++) {
            tmp = beg;
            bool changed = false;
            for (int j = 0; j < s1.size(); j++) {
                if (s1[j] == '1' && tmp&(1<<j)) {
                    tmp ^= (1 << j);
                    changed = true;
                }
            }
            for (int j = 0; j < s2.size(); j++) {
                if (s2[j] == '1') {
                    tmp |= (1 << j);
                }
            }
            if (changed) {
                adj[beg].push_back({tmp, d}); 
            }
        }
    }

    priority_queue<arr, vector<arr>, greater<arr>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto tp = pq.top();
        int u = tp[1], time = tp[0];
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        dist[u] = time;
        for (auto [v, d] : adj[u]) {
            if (dist[v] > dist[u] + d) {
                dist[v] = dist[u] + d;
                pq.push({dist[v], v});
            }
        }
    }
    cout << (dist[0] > (int)1e9 ? -1 : dist[0]) << '\n';
}

/*
   Each node is actually a bitset of symptoms. Each edge is
   a medicine that will take you from symptom X to symptom Y.
   Use BFS to find the shortest path to the all 0s symptom.
*/







