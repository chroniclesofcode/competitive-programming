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
    cin >> n;
    vector<double> d(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    cout << "aloha...";
    string ans = "{d:";
    int i = 1;
    vector<pair<double,int>> bl(16);
    for (; i <= n-16; i += 16) {
        int j = i;
        bl.clear();
        for (int k = 0; k < 16; k++) {
            bl.push_back({d[j+k], j+k});
        }
        sort(bl.begin(), bl.end());
        ans += "{s:";
        for (int k = 0; k < 16; k++) {
            ans += to_string(bl[k].second);
            if (k != 15) ans += ",";
        }
        ans += "}";
        if (i+16 <= n-16) ans += ",";
    }
    bl.clear();
    for (int k = i; k <= n; k++) {
        bl.push_back({d[k], k});
    }
    sort(bl.begin(), bl.end());
    if (bl.size()) {
        if (n > 16) ans += ",";
        ans += "{s:";
        for (int k = 0; k < bl.size(); k++) {
            ans += to_string(bl[k].second);
            if (k != bl.size() - 1) ans += ",";
        }
        ans += "}";
    }
    ans += "}";
    cout << ans << '\n';
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
