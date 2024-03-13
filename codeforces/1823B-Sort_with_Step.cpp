#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k;
int mark[MX];

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int error = 0;
    vector<int> v;
    for (int i = 0; i < k; i++) {
        v.clear();
        for (int j = i; j < n; j += k) {
            mark[a[j]-1] = 1;
            v.push_back(a[j]-1);
        }
        for (int j = i; j < n; j += k) {
            if (!mark[j]) {
                error++;
            }
        }
        for (auto e : v) mark[e] = 0;
    }
    if (error == 0) {
        cout << "0\n";
    } else if (error > 2) {
        cout << "-1\n";
    } else {
        cout << "1\n";
    }
}

/*

*/







