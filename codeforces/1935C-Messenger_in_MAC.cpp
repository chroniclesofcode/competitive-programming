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

void solve() {
    cin >> n >> k; // msgs, upper lim
    vector<arr2> v(n);
    int run = INF;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v[i] = {b, a};
        run = min(run, a);
    }
    if (run > k) {
        cout << "0\n"; return;
    }
    int ans = 1;
    sort(v.begin(), v.end()); // {b,a} sorted b ascend
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        pq = {};
        int pqtot = 0;
        int ct = 0;
        for (int j = i; j < n; j++) {
            int diff = v[j][0] - v[i][0];
            if (diff > k) break;
            pq.push(v[j][1]);
            pqtot += v[j][1];
            while (!pq.empty() && pqtot + diff > k) {
                pqtot -= pq.top();
                pq.pop();
            }
            ct = max(ct, (int)pq.size());
        }
        ans = max(ans, ct);
    }
    cout << ans << '\n';
}
/*
   dp[i][j] = 0..i length, max length under lim ending at j
*/







