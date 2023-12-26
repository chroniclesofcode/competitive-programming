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

        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;


void solve() {
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    int sum = 0;
    int ans = INF;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        sum += h[i];
        if (i >= k) {
            sum -= h[i-k];
        }
        if (i >= k-1 && sum < ans) {
            ans = sum;
            ret = i-(k-1)+1;
        }
    }
    cout << ret << '\n';
}

/*

*/



