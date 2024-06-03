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

LL n, m, k;


void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<LL> pref;
    if (k > 0) {
        sort(a.begin(), a.end());
        cout << "Yes\n";
        for (auto e : a) cout << e << ' '; cout << '\n';
        return;
    }
    LL run = 0;
    LL big = LLONG_MIN;
    LL small = LLONG_MAX;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        run += a[i];
        pref.push_back(run);
    }
    for (int i = 0; i < n; i++) {
        big = max(big, pref[i]);
        small = min(small, pref[i]);
    }
    if (small >= k) {
        cout << "Yes\n";
        for (auto e : a) cout << e << ' '; cout << '\n';
        return;
    }

    run = 0;
    pref.clear();
    big = LLONG_MIN;
    small = LLONG_MAX;
    sort(a.begin(), a.end(), greater<LL>());
    for (int i = 0; i < n; i++) {
        run += a[i];
        pref.push_back(run);
    }
    for (int i = 0; i < n; i++) {
        big = max(big, pref[i]);
        small = min(small, pref[i]);
    }
    if (small < k) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (auto e : a) cout << e << ' '; cout << '\n';
}

/*
   -4 -2 1 3
   -4 -6 -5 -2
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
