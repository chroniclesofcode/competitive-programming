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

long long n, m, k, q;

long long binsearch(long long st) {
    long long lo = 1, hi = sqrt(n/2)+1;
    long long ans = 0;
    while (lo <= hi) {
        long long mid = lo + (hi-lo)/2;
        long long tmp = st*mid*mid;
        if (tmp <= n) {
            ans = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    return ans;
}
void solve() {
    cin >> n;
    long long ans1 = binsearch(2);
    long long ans2 = binsearch(4);
    cout << ans1 + ans2 << '\n';
}

/*

*/