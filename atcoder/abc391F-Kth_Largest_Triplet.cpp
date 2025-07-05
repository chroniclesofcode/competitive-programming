#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
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

LL calc(LL i, LL j, LL k) {
    return i*j + j*k + k*i;
}

void solve() {
    cin >> n >> k;
    vector<long long> a(n), b(n), c(n);
    for (LL i = 0; i < n; i++) {
        LL t; cin >> t;
        a[i] = t;
    }
    for (LL i = 0; i < n; i++) {
        LL t; cin >> t;
        b[i] = t;
    }
    for (LL i = 0; i < n; i++) {
        LL t; cin >> t;
        c[i] = t;
    }
    sort(a.begin(), a.end(), greater<LL>());
    sort(b.begin(), b.end(), greater<LL>());
    sort(c.begin(), c.end(), greater<LL>());
    using arr4 = array<long long,4>;
    priority_queue<arr4> pq;
    long long fst = calc(a[0],b[0],c[0]);
    pq.push({fst, 0, 0, 0});
    long long ans = fst;
    map<arr3,long long> mp;
    long long ct = 0;
    while (ct < k) {
        auto tp = pq.top();
        pq.pop();
        long long x = tp[1], y = tp[2], z = tp[3];
        if (mp[{x,y,z}]) continue;
        ct++;
        mp[{x,y,z}] = 1;
        if (x+1 < n)
            pq.push({calc(a[x+1],b[y],c[z]),x+1,y,z});
        if (y+1 < n) 
            pq.push({calc(a[x],b[y+1],c[z]),x,y+1,z});
        if (z+1 < n)
            pq.push({calc(a[x],b[y],c[z+1]),x,y,z+1});
        ans = tp[0];
    }
    cout << ans << '\n';
}

/*
1 2
3 4
5 6

2,4,6
2,4,5
2,3,6
2,3,5
1,4,6
1,4,5
1,3,6
1,3,5
*/