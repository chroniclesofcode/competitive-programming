#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define prLL_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<LL,2>
#define arr3 array<LL,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr LL INF = (LL)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;

void solve() {
    cin >> n;
    vector<LL> a(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<LL> trip(3);
    map<arr3, LL> mp;
    LL ans = 0;
    vector<arr3> nums;
    for (int i = 0; i < n-2; i++) {
        nums.push_back({a[i],a[i+1],a[i+2]});
    }
    sort(nums.begin(), nums.end());
    for (auto &trip : nums) {
        ans += mp[{-1, trip[1], trip[2]}];
        ans += mp[{trip[0], -1, trip[2]}];
        ans += mp[{trip[0], trip[1], -1}];
        ans -= mp[{trip[0], trip[1], trip[2]}] * 3;
        mp[{-1, trip[1], trip[2]}]++;
        mp[{trip[0], -1, trip[2]}]++;
        mp[{trip[0], trip[1], -1}]++;
        mp[{trip[0], trip[1], trip[2]}]++;
    }
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
