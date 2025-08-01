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
    int n, r, c;
    cin >> n >> r >> c;
    string s;
    cin >> s;
    map<arr2, int> m;
    string ans(n, '0');
    m[{0,0}] = 1;
    arr2 curr = {0, 0};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N') {
            curr[0]--;
        } else if (s[i] == 'W') {
            curr[1]--;
        } else if (s[i] == 'S') {
            curr[0]++;
        } else if (s[i] == 'E') {
            curr[1]++;
        }
        int dx = curr[0]-r, dy = curr[1]-c;
        if (m.find({dx, dy}) != m.end()) {
            ans[i] = '1';
        }
        m[curr] = 1;
    }
    cout << ans << '\n';
}

/*
For each individual cloud, how much does it hit the point?
And each cloud is actually just a suffix of the entire
array!
To reach that spot, every cloud needs to have at some point
reached a NET total of + and - to (R, C).
So, we need to count how many times that occurs.

*/