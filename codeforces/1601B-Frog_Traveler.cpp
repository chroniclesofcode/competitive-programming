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

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

void solve() {
    cin >> n;
    vector<int> a(n+1), b(n+1), prev(n+1), dp(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    std::function<void(int)> recurse = [&](int u) {
        if (u == n) return;
        recurse(prev[u]);
        cout << u << ' ';
    };

    int reach = n;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == 0) {
            cout << dp[u] << '\n';
            recurse(u);
            cout << '\n';
            return;
        }
        int slid = u + b[u];
        for (int i = min(slid-1, reach-1); i >= slid-a[slid]; i--) {
            dp[i] = dp[u]+1;
            prev[i] = u;
            q.push(i);
        }
        reach = min(reach, slid - a[slid]);
    }
    cout << "-1\n";
}

/*
   dp[i] represents min time to reach point BEFORE sliding.
   Anywhere we can reach, we jump there, and when we pop
   off the queue, that's when we do the slide-down processing
   instead of trying to do both at once.

   After we slide down, we iterate through everything we can
   jump to, BUT! we don't want to push anything we've already
   pushed onto the queue, since it can only be slower (BFS).

   So we maintain a reach variable, which is the furthest we've
   jumped. We always want to start past this variable, otherwise
   we will double jump on the same element. This keeps it O(n).
*/



