#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
#define NINF -INF

const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

LL dp[20][2][10];
/*

*/


LL query(LL x) {
    if (x < 0) return 0;
    if (x == 0) return 1;
    string ss = to_string(x);
    int n = ss.size();
    memset(dp, 0, sizeof(dp));
    LL ans = 1;
    LL pow9 = 1;
    vector<LL> pp;
    pp.push_back(1);
    for (int i = 1; i <= 18; i++) {
        pow9 *= 9;
        pp.push_back(pow9);
        if (i < n-1)
            ans += pow9;
    }
    for (int i = 0; i < n; i++) {
        int pr = n-i-1;
        ans += (ss[i]-'0') * pp[pr];
        if (i > 0 && ss[i] > ss[i-1]) {
            ans -= pp[pr];
        }
        if (i > 0 && ss[i] == ss[i-1]) return ans;
    }
    return ans+1;
}

void solve() {
    long long a, b;
    cin >> a >> b;
    cout << (query(b) - query(a-1)) << '\n';
}





