#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define prLL_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<LL,2>
#define arr3 array<LL,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr LL INF = (LL)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, q;

class Fenwick {
public:
    LL n;
    vector<LL> BIT;

    Fenwick() {}
    Fenwick(LL sz) : n{sz}, BIT(sz+1, 0) {}

    void add(LL x, LL add) {
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

    LL pref(LL st, LL end) {
        if (st > end) return 0;
        return st <= 0 ? query(end) : query(end) - query(st-1);
    }
};

// lowest element that is greater than target
LL lowerb(vector<arr2>& nums, Fenwick& ft, LL target) {
    LL lo = 0, hi = nums.size() - 1;
    LL ans = q;
    while (lo <= hi) {
        LL mid = lo + (hi-lo)/2;
        LL val = nums[mid][0] + ft.query(mid);
        if (val >= target) {
            hi = mid-1;
            ans = min(ans, mid);
        } else {
            lo = mid+1;
        }
    }
    return ans;
}

// greatest element that is less than target
LL upperb(vector<arr2>& nums, Fenwick& ft, LL target) {
    LL lo = 0, hi = nums.size() - 1;
    LL ans = -1;
    while (lo <= hi) {
        LL mid = lo + (hi-lo)/2;
        LL val = nums[mid][0] + ft.query(mid);
        if (val <= target) {
            lo = mid+1;
            ans = max(ans, mid);
        } else {
            hi = mid-1;
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    vector<arr2> range(n);
    for (LL i = 0; i < n; i++) {
        LL l, r; cin >> l >> r;
        range[i] = {l, r};
    }
    cin >> q;
    vector<arr2> queries(q);
    for (LL i = 0; i < q; i++) {
        LL tmp; cin >> tmp;
        queries[i] = { tmp, i };
    }
    sort(queries.begin(), queries.end());
    Fenwick ft(q + 10);
    for (LL i = 0; i < n; i++) {
        auto [l, r] = range[i];
        LL bot = lowerb(queries, ft, l);
        LL top = upperb(queries, ft, r);
        if (bot > top) continue;
        ft.add(bot, 1);
        ft.add(top+1, -1);
    }
    vector<LL> ans(q);
    for (LL i = 0; i < q; i++) {
        ans[queries[i][1]] = queries[i][0] + ft.query(i);
    }
    for (LL i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}

/*

Basically, sort the queries, order them by their actual values
then for every range, binary search to find the beginning and
the end, and increment for every l,r.
*/