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
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k, q;

// note 1-indexed
void solve() {
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> ct;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ct[a[i]]++;
    }
    int ans = 0;
    int curr = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (ct[a[i]] == 1) {
            curr++;
        } else curr = 0;
        if (curr > ans) {
            ans = curr;
            r = i+1;
            l = r - curr + 1;
        }
        ans = max(ans, curr);
    }
    if (l == 0 || r == 0) {
        cout << 0 << '\n';
        return;
    }
    cout << l << ' ' << r  << '\n';
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
