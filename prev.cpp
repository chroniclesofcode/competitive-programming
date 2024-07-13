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

class FenwickArr {
public:
    using LL = long long;
    LL n;
    vector<LL> BIT;
    vector<LL> arr;

    FenwickArr() {}
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
        if (st > end) return 0;
        return st <= 0 ? query(end) : query(end) - query(st-1);
    }
};

class Fenwick2D {
public:
    int n, m;
    vector<vector<int>> BIT;

    Fenwick2D(int sn, int sm) : n{sn}, m{sm}, BIT(sn+1, vector<int>(sm+1)) {}

    void add(int x, int y, int add) {
        x++; y++;
        for (int i = x; i <= n; i += i&-i) {
            for (int j = y; j <= m; j += j&-j) {
                BIT[i][j] += add;
            }
        }
    }

    int query(int x, int y) {
        x++; y++;
        int sum = 0;
        for (int i = x; i > 0; i -= i&-i) {
            for (int j = y; j > 0; j -= j&-j) {
                sum += BIT[i][j];
            }
        }
        return sum;
    }
};

void solve() {
    cin >> n;
}

/*

*/



