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
    string s;
    cin >> s;
    int same = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i-1]) same = 0;
    }
    if (same || s.size() <= 1) {
        cout << "-1\n";
        return;
    }
    s.pop_back();
    cout << s.size() << '\n';
}

/*

*/







