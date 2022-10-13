#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

#define INF numeric_limits<LL>::max() / 2
const int MX = 1e4;
int q[MX];
int a[MX], b[MX], c[MX];
multimap<int, pair<int, int>> mm;
unordered_map<int, int> has;

/*
   Sort the applications with min costs first
   Greedily assign supervisors IF they have no
   supervisor and they are not currently attached
   to someone
   map has says i has a supervisor
   array adj says there's a connection to someone
*/

void solve() {
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        mm.insert(make_pair(c[i], make_pair(a[i],b[i])));
    }
    int ret = 0;
    for (auto it = mm.begin(); it != mm.end(); it++) {
        int cost = it->first;
        int fir = it->second.first;
        int sec = it->second.second;
        if (!has[sec] && q[fir] > q[sec]) {
            ret += cost;
            has[sec] = 1;
        }
    }

    int ct = 0;
    for (int i = 1; i <= n; i++) {
        if (has[i]) {
            ct++;
        }
    }
    cout << (ct == n - 1 ? ret : -1) << '\n';



}

