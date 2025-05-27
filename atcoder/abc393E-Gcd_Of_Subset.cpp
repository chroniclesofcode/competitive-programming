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
    cin >> n >> k;
    vector<int> a(n);
    int M = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
        M = max(M, x);
    }
    vector<int> s(M+1);
    for (int i = 0; i < n; i++) {
        s[a[i]]++;
    }
    vector<int> ct(M+1);
    for (int i = 1; i <= M; i++) {
        for (int j = i; j <= M; j += i) {
            ct[i] += s[j];
        }
    }
    vector<int> ans(M+1);
    for (int i = 1; i <= M; i++) {
        if (ct[i] < k) continue;
        for (int j = i; j <= M; j += i) {
            ans[j] = max(ans[j], i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[a[i]] << '\n';
    }
}

/*

*/