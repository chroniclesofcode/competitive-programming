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

class Fenwick {
public:
    int n;
    vector<int> BIT;

    Fenwick() {}
    Fenwick(int sz) : n{sz}, BIT(sz+1, 0) {}

    void add(int x, int add) {
        x++;
        for (; x <= n; x += x&-x) {
            BIT[x] += add;
        }
    }

    int query(int x) {
        x++;
        int sum = 0;
        for (; x > 0; x -= x&-x) {
            sum += BIT[x];
        }
        return sum;
    }

    int pref(int st, int end) {
        if (st > end) return 0;
        return st <= 0 ? query(end) : query(end) - query(st-1);
    }
};

void solve() {
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        vals[i] = p;
    }
    Fenwick ft(n+1);
    for (int i = 0; i < n; i++) {
        ft.add(i, 1); // represents empty slots
    }
    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--) {
        int val = vals[i];
        int lo = 0, hi = n-1;
        int ret = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            int qu = ft.query(mid);
            if (qu >= val) {
                ret = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        ans[ret] = i+1;
        ft.add(ret, -1);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

/*

*/