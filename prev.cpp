#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

LL n, m, d;

/*

*/

void solve() {
    cin >> n >> m >> d;
    vector<LL> sellers;
    sellers.push_back(0);
    LL x;
    bool is0 = false;
    for (LL i = 0; i < m; i++) {
        cin >> x;
        x--;
        if (x == 0) is0 = true;
        if (x != 0)
            sellers.push_back(x);
    }
    LL tot = 1;
    LL sz = sellers.size();
    LL mx = 0;
    LL idx = sellers[sz-1];
    LL ct = 0;
    for (LL i = 1; i < sz; i++) {
        // total cookies eaten
        tot += 1 + (sellers[i] - sellers[i-1] - 1) / d;

        // cookies eaten without current
        LL ckw = 0;
        // cookies eaten with current
        LL withc = 0;
        if (i < sz-1) {
            ckw = (sellers[i+1] - sellers[i-1] - 1)/d;
            withc = 1 + (sellers[i]-sellers[i-1]-1)/d + (sellers[i+1]-sellers[i]-1)/d;

        } else {
            ckw = (n - sellers[i-1] - 1)/d;
            withc = 1 + (sellers[i]-sellers[i-1]-1)/d + (n-sellers[i]-1)/d;
        }
        LL dif = withc - ckw;
        if (dif > mx) {
            mx = dif;
            ct = 1;
        } else if (dif == mx) {
            ct++;
        }
    }
    tot += (n - sellers[sz-1] - 1) / d;
    if (mx == 0 && is0) {
        cout << tot << ' ' << ct+1 << '\n';
    } else {
        cout << tot - mx << ' ' << ct << '\n';
    }
}





