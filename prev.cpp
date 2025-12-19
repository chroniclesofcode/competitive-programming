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
    cin >> k;
    string s, t;
    cin >> s;
    cin >> t;
    LL ct = 0;
    
    int i = 0, j = 0;
    int n = s.size(), m = t.size();
    while (1) {
        if (i < n && j >= m) {
            ct++;
            i++;
            continue;
        } else if (i >= n && j < m) {
            ct++;
            j++;
            continue;
        } else if (i >= n && j >= m) {
            break;
        }
        if (s[i] == t[j]) {
            i++; j++;
        } else {
            ct++;
            if (n < m) {
                j++;
            } else if (m < n) {
                i++;
            } else {
                i++; j++;
            }
        }
    }
    if (ct > k) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

/*

*/