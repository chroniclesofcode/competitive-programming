#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 10000;
const LL MOD = 1e9 + 7;

LL a, b;
LL dp[20][2];


LL digitdp(string s) {

}

void resetdp() {
    memset(dp, 0, sizeof dp);
}

void solve() {
    cin >> a >> b;
    LL r1 = digitdp(to_string(b));
    resetdp();
    LL r2 = digitdp(to_string(a));
    
    cout << r1 - r2 << endl;
}





