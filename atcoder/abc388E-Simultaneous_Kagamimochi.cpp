#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k, q;


void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lo = 0, hi = n/2;
    int ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        int valid = 1;
        for (int i = 0; i < mid; i++) {
            if (a[i]*2 > a[n-mid+i]) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            ans = max(ans, mid);
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    cout << ans << endl;
}

/*

*/