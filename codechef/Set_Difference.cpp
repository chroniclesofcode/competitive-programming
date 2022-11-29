#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();
LL casenum;
const LL MX = 1e5+20;
LL power[MX];
const LL MOD = 1e9 + 7;

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    power[0] = 1;
    power[1] = 2;
    for (LL i = 2; i <= MX; i++) {
        power[i] = power[i-1] * 2;
        power[i] %= MOD;
    }
    LL t;
    cin >> t;
    while (t--) 
        solve();
}

#define INF numeric_limits<LL>::max() / 2

LL a[MX];
LL n;

void solve() {
    cin >> n;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    LL mins = 0, maxes = 0;
    LL ret = 0;
    for (LL i = 0; i < n; i++) {
        LL front = n - i - 1;
        LL back = i; 
        mins = a[i] * (power[front] - 1);
        //mins %= MOD;
        maxes = a[i] * (power[back] - 1);
        //maxes %= MOD;
        ret += maxes - mins;
        ret = ((ret%MOD)+MOD)%MOD;
    }
    cout << ret << '\n';
}

/*

*/

