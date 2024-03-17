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
    cin >> n >> k;
    vector<int> lens(k), subs(k);
    for (int i = 0; i < k; i++) cin >> lens[i];
    for (int i = 0; i < k; i++) cin >> subs[i];
    int curr = 0, letter = 'd';
    string ans = "";
    int len, sub, diff = 0, prev = 0;
    int use = 3;
    vector<char> lets = { 'a', 'b', 'c' };
    int ct = 0;
    for (int i = 0; i < k; i++) {
        len = lens[i], sub = subs[i];
        diff = sub - prev;
        int rem = len-ans.size();
        if (diff > rem || diff < 0) {
            cout << "NO\n"; return;
        }
        int tmp = min(diff, use);
        diff -= tmp;
        use -= tmp;
        for (int j = 0; j < diff; j++) {
            ans += letter;
        }
        for (int j = 0; j < rem - diff; j++) {
            ans += lets[(ct++)%3];
        }
        letter++;
        prev = sub;
    }
    ans += string(n - ans.size(), 'a');
    cout << "YES\n";
    cout << ans << '\n';
}

/*

*/







