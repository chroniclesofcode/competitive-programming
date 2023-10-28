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
    string s;
    cin >> s;
    LL ct = 0, run = 0, prev = 0, j = n-1;
    for (LL i = n-1; i >= 0; i--) {
        if (s[i] == '1') ct++;
        else {
            run += ct;
            cout << run << ' ';
            j--;
        }
    }
    while (j >= 0) {
        cout << -1 << ' ';
        j--;
    }
    cout << '\n';
}




 
