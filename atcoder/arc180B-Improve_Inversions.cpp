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


void solve() {
    cin >> n >> k;
    vector<int> p(n), inv(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i]; p[i]--;
        inv[p[i]] = i;
    }
    vector<pair<int,int>> ans;
    for (int i = 0; i < n; i++) {
        int idx = inv[i];
        vector<int> valid;
        for (int j = idx + k; j < n; j++) {
            if (p[j] < i) {
                valid.push_back(p[j]);
            }
        }
        sort(valid.begin(), valid.end(), greater<int>());
        for (int j = 0; j < valid.size(); j++) {
            int v = inv[valid[j]];
            ans.push_back({idx, v});
            swap(inv[p[idx]], inv[p[v]]);
            swap(p[idx], p[v]);
        }
    }
    cout << ans.size() << '\n';
    for (auto &a : ans) {
         cout << a.first+1 << ' ' << a.second+1 << '\n';
    }
}

/*
   1 2 3
   3 2 1
   swap values 1,2
   1 2 3
   2 3 1
   swap values 1,3
   1 2 3
   1 3 2
   swap values 2,3
   1 2 3
   1 2 3


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
