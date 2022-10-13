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
const int MX = 1e5 + 100;
set<int> adj[MX];
unordered_map<int, int> m;
vector<int> ret;
/*
    we find vertex with 3+ paths attached
    to it, that has to be the root. If there
    are multiple, then we show there are no valid
    decompositions. If there are none, then it's
    a linked list, then just choose the two ends -
    these will be the ones with only 1 connection

*/

void solve() {
    int n;
    cin >> n;
    bool pathexists = true;
    bool root = false;
    int begin = 0;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
        m[a]++;
        m[b]++;
        if (m[a] == 3) {
            if (root) {
                pathexists = false;
            }
            root = true;
            begin = a;
        } else if (m[b] == 3) {
            if (root) {
                pathexists = false;
            }
            root = true;
            begin = b;
        }
    }
    if (!pathexists) {
        cout << "No\n";
        return;
    }
    
    if (!root) {
        cout << "Yes\n1\n";
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) {
                cout << it->first << " ";
            }
        }
        cout << '\n';
        return;
    }
    cout << "Yes\n";
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second == 1 && it->first != begin) {
            ret.push_back(it->first);
        }
    }
    cout << ret.size() << '\n';
    for (int i = 0; i < ret.size(); i++) {
        cout << begin << " " << ret[i] << '\n';
    }
}

