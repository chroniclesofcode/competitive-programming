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
int a, b;
vector<int> divisors;
unordered_map<int, int> vis;

void getDivisors(vector<int>& factors, vector<int>& div, int idx = 0, int res = 1) {
    
    if (idx == factors.size()) {
        if (vis[res]) return;
        vis[res] = 1;
        div.push_back(res);
        return;
    }
    getDivisors(factors, div, idx+1, res);
    getDivisors(factors, div, idx+1, res*factors[idx]);
}

void solve() {
    // PREPROCESSING SIEVE
    constexpr int LIM = (int)1e5;
    vector<int> is_p(LIM+1, true);
    vector<int> primes;
    is_p[0] = is_p[1] = false;
    for (int i = 2; i*i <= LIM; i++) {
        if (is_p[i]) {
            for (int j = i*i; j <= LIM; j += i) {
                is_p[j] = false;
            }
        }
    }
    for (int i = 2; i <= LIM; i++) {
        if (is_p[i]) primes.push_back(i);
    }
    // TAKE INPUT
    cin >> a >> b;
    vector<int> fact1, fact2;
    for (auto pr : primes) {
        if (pr * pr > a) break;
        while (a % pr == 0) {
            fact1.push_back(pr);
            a /= pr;
        }
    }
    if (a > 1) fact1.push_back(a);
    for (auto pr : primes) {
        if (pr * pr > b) break;
        while (b % pr == 0) {
            fact2.push_back(pr);
            b /= pr;
        }
    }
    if (b > 1) fact2.push_back(b);
    vector<int> da, db;
    getDivisors(fact1, da);
    divisors.clear(); vis.clear();
    getDivisors(fact2, db);
    vector<int> common;
    for (auto d1 : da) {
        for (auto d2 : db) {
            if (d1 == d2) common.push_back(d1);
        }
    }
    // QUERIES
    sort(common.begin(), common.end());
    cin >> n;
    for (int i = 0; i < n; i++) {
        int lo, hi; cin >> lo >> hi;
        auto it = upper_bound(common.begin(), common.end(), hi);
        if (it != common.begin()) it--;
        if (*it >= lo && *it <= hi) {
            cout << *it << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}

/*

*/







