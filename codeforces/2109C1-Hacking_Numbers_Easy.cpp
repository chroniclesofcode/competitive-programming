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

LL n, m, k, q;

int dig(int tmp) {
    int ans = 0;
    while (tmp > 0) {
        ans += tmp % 10;
        tmp /= 10;
    }
    return ans;
}

void solve() {
    LL target;
    cin >> target;
    cout << "digit" << endl;
    LL res;
    cin >> res;
    cout << "digit" << endl;
    cin >> res;
    cout << "mul 3" << endl;
    cin >> res;
    cout << "digit" << endl;
    cin >> res;
    cout << "div 6" << endl;
    cin >> res;
    if (res == 1) {
        cout << "div 2" << endl;
        cin >> res;
        cout << "add " << target - 1 << endl;
        cin >> res;
    } else {
        cout << "div 9" << endl;
        cin >> res;
        if (res) {
            cout << "add " << target - 1 << endl;
        } else {
            cout << "add " << target - 3 << endl;
        }
        cin >> res;
    }
    cout << "!" << endl;
    cin >> res;
}

/*

*/