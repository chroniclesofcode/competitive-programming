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
    cin >> n >> q;
    string str;
    cin >> str;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int idx = i+1;
        if (idx % 2 == 0 && str[i] == '(') {
            s.insert(idx);
        } else if (idx % 2 == 1 && str[i] == ')') {
            s.insert(idx);
        }
    }
    int odd = str.size() % 2 == 1;
    for (int i = 0; i < q; i++) {
        int idx; cin >> idx;
        if (odd) { cout << "NO\n"; continue; }
        int j = idx-1;
        if (str[j] == ')') str[j] = '(';
        else if (str[j] == '(') str[j] = ')';
        s.erase(idx);
        if (idx % 2 == 0 && str[j] == '(') s.insert(idx);
        else if (idx % 2 == 1 && str[j] == ')') s.insert(idx);

        if (s.empty() || (*s.begin() % 2 == 0 && *std::prev(s.end()) % 2 == 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

/*

*/

/*
   Try this if you are stuck:
1) binary search on answer
2) Try solving it in reverse
3) Think of a simpler problem 
4) Think of elements which are special
   (like minimum, maximum, deepest node in tree, root)
5) Is it graph problem?
    - super node? dp? cycles?
6) sorting on something e.g. queries?
7) Parity? something special
8) is it monotonic? could you use a PQ/stack/queue?

   EDGE CASES! N = 1, 2...
   LONG LONG
*/
