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
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]] = 1;
    }
    int mex = 0;
    for (int i = 0; i <= n; i++) {
        if (!m[i]) {
            mex = i;
            break;
        }
    }
    a.push_back(mex);
    int sz = a.size();
    int shift = k % sz;
    int start = sz-shift;
    if (start == sz) start = 0;
    for (int i = 0; i < n; i++) {
        cout << a[start] << ' ';
        start = (start + 1) % sz;
    }
    cout << '\n';
}

/*

*/







