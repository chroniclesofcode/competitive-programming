#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<int,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

class Fenwick {
public:
    int n;
    vector<int> BIT;

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
};

class FenwickArr {
public:
    LL n;
    vector<LL> BIT;
    vector<LL> arr;

    FenwickArr(LL sz) : n{sz}, BIT(sz+1, 0), arr(sz) {}

    void add(LL x, LL add) {
        arr[x] += add;
        x++;
        for (; x <= n; x += x&-x) {
            BIT[x] += add;
        }
    }

    LL query(LL x) {
        x++;
        LL sum = 0;
        for (; x > 0; x -= x&-x) {
            sum += BIT[x];
        }
        return sum;
    }

    void set(LL idx, LL val) {
        add(idx, val - arr[idx]);
    }

    LL pref(LL st, LL end) {
        return st <= 0 ? query(end) : query(end) - query(st-1);
    }
};

void solve() {
    cin >> n;
}

/*

*/



