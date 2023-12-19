#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

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
constexpr LL LINF = LLONG_MAX / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;
int mark[MX];

void solve() {
    cin >> n;
    string s;
    cin >> s;
    queue<int> q[26];
    memset(mark, 0, 4 * (n+1));
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        q[c].push(i);
    }
    int last = -1;
    int ans = 0;
    string tmp;
    for (int j = 25; j >= 0; j--) {
        while (!q[j].empty() && q[j].front() < last) {
            q[j].pop();
        }
        while (!q[j].empty()) {
            int f = q[j].front();
            q[j].pop();
            mark[f] = 1;
            last = f;
            tmp.push_back(j + 'a');
        }
    }
    string inorder = s;
    sort(inorder.begin(), inorder.end());
    for (int i = 0; i < n; i++) {
        if (!mark[i] && s[i] != inorder[i]) {
            cout << -1 << '\n'; return;
        }
    }
    int lead = 1;
    for (int i = 1; i < tmp.size(); i++) {
        if (tmp[i] > tmp[i-1]) {
            cout << -1 << '\n'; return;
        }
    }
    for (int i = 1; i < tmp.size(); i++) {
        if (tmp[i] == tmp[i-1]) {
            lead++;
        } else {
            break;
        }
    }

    cout << tmp.size() - lead << '\n';
}

/*

*/







