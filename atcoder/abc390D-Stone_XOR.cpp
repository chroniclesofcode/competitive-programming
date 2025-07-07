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

        solve();
}

constexpr LL INF = (LL)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, q;
vector<LL> a;
vector<LL> s;
unordered_set<LL> mp;
LL val = 0;
LL vis[13];

void dfs(LL idx, LL sz){
	for(LL i = 0; i <= sz; i++) {
		val ^= s[i];
		s[i] += a[idx];
		val ^= s[i];
		if (idx == n-1) { 
            mp.insert(val);
        } else if (i < sz) dfs(idx+1, sz);
		else dfs(idx+1, sz+1);
		val ^= s[i];
		s[i] -= a[idx];
		val ^= s[i];
	}
	return;
}

void solve() {
    cin >> n;
    a = vector<LL>(n);
    for (LL i = 0; i < n; i++) cin >> a[i];
    s = vector<LL>(n, 0);
    dfs(0,0);
    cout << mp.size() << '\n';
}

/*

*/