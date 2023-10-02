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

int n;

/*

*/

void solve() {
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    } else if (n % 2 == 1) {
        cout << -1 << '\n';
        return;
    } 
    //int odds = n-1;
    int odds = 1;;
    int evens = 2;
    for (int i = 0; i < n/2; i++) {
        cout << evens << ' ' << odds << ' ';
        odds = (odds + 2)% n;
        evens += 2;
    }
    cout << '\n';
}





