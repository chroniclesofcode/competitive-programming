#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
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

LL n;

/*

*/

void solve() {
    cin >> n;
    vector<LL> a;
    LL oct = 0;
    LL tot = 0;
    for (LL i = 0; i < n; i++) {
        LL x; cin >> x;
        if (x == 1) oct++;
        tot += x;
        a.push_back(x);
    }
    if (n == 1 || oct == n || tot - 2*oct < n-oct) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}




 
