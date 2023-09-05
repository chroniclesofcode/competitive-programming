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

int n;

/*
   for each k, iterate through all multiples of k
   inside string until we hit a value that is not
   meant to be deleted.
*/

void solve() {
    cin >> n;
    string s;
    cin >> s;
    vector<bool> b(s.size()+1, true);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i-1; j < n; j += i) {
            if (b[j] && s[j] == '1') {
                break;
            } else if (b[j] && s[j] == '0') {
                b[j] = false;
                ans += i;
            }
        }
    }
    cout << ans << '\n';
}





