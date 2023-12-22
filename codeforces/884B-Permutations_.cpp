#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<int,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

void solve() {
    cin >> n;
    vector<int> ans(n, -1);
    if (n == 1) {
        cout << "1\n";
        return;
    } else if (n == 2) {
        cout << "1 2\n";
        return;
    }
    ans[0] = 2;
    ans[n-1] = 3;
    ans[n/2] = 1;
    int j = 1;
    for (int i = 4; i <= n; i++) {
        while (j < n && ans[j] != -1) {
            j++;
        }
        ans[j] = i;
    }
    for (auto a : ans) {
        cout << a << ' ';
    }
    cout << '\n';
}

/*

*/







