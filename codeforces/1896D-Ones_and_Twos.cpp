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

#define INF numeric_limits<LL>::max() / 2
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

int n, q;
/*

*/

void solve() {
    cin >> n >> q;
    vector<int> a;
    set<int> ones;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
        if (x == 1) ones.insert(i);
    }
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int s; cin >> s;
            int tot = ones.size() + 2 * (n - ones.size());
            if (tot < s) {
                cout << "NO\n"; continue;
            }
            if ((tot-s)%2 == 0) {
                cout << "YES\n"; continue;
            }
            if (ones.size() == 0) {
                cout << "NO\n"; continue;
            }
            int l = *ones.begin(), r = *ones.rbegin();
            int lsum = 1 * (ones.size() - 1) + 2 * (r - (ones.size()-1));
            int rsum = 1 * (ones.size() - 1) + 2 * ((n-l-1) - (ones.size()-1));
            if ((lsum >= s && (lsum-s)%2==0) || (rsum >= s && (rsum-s)%2==0)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            int idx, v; cin >> idx >> v;
            idx--;
            if (v == 1) {
                ones.insert(idx);
            } else {
                auto it = ones.find(idx);
                if (it != ones.end()) ones.erase(it);
            }
        }
    }
}





