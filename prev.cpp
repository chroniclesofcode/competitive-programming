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
    unordered_map<int,int> pigeon;
    unordered_map<int,int> nest;
    unordered_map<int,int> rev;
    for (int i = 1; i <= n; i++) {
        pigeon[i] = i; // points to nest[i]
        nest[i] = i;
        rev[i] = i;
    }
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int a, b; cin >> a >> b;
            // move pigeon a to nest b
            pigeon[a] = nest[b];
        } else if (op == 2) {
            int a, b; cin >> a >> b;
            // swap pigeons in nest a and b
            swap(nest[a], nest[b]);
            rev[nest[a]] = a;
            rev[nest[b]] = b;
        } else if (op == 3) {
            int a; cin >> a;
            // what nest is pigeon a in?
            cout << rev[pigeon[a]] << '\n';
        }
    }
}

/*

*/