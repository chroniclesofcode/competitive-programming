#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k;
string s, t;
unordered_map<string, int> vis;

void solve() {
    cin >> n; cin >> s >> t;

    s += "__"; t += "__";
    queue<string> q;
    q.push(s);
    int level = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            string tp = q.front();
            q.pop();
            if (vis[tp] == 1) continue;
            vis[tp] = 1;
            if (tp == t) {
                cout << level << '\n'; return;
            }
            int loc = 0;
            for (int i = 0; i < tp.size(); i++) {
                if (tp[i] == '_') {
                    loc = i; break;
                }
            }
            for (int i = 0; i < tp.size()-1; i++) {
                if (tp[i] != '_' && tp[i+1] != '_') {
                    swap(tp[i], tp[loc]);
                    swap(tp[i+1], tp[loc+1]);
                    if (!vis[tp]) {
                        q.push(tp);
                    }
                    swap(tp[i], tp[loc]);
                    swap(tp[i+1], tp[loc+1]);
                }
            }
        }
        level++;
    }
    cout << "-1\n";
}

/*

*/

/*
   Try this if you are stuck:
1) binary search on answer
2) Try solving it in reverse
3) Think of a simpler problem 
4) Think of elements which are special
   (like minimum, maximum, deepest node in tree, root)
5) Is it graph problem?
    - super node? dp? cycles?
6) sorting on something e.g. queries?
7) Parity? something special
8) is it monotonic? could you use a PQ/stack/queue?

   EDGE CASES! N = 1, 2...
   LONG LONG
*/
