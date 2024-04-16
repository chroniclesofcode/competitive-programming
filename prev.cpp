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
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 3*(int)1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

class SieveOfE {
public:
    vector<int> is_p;
    vector<int> primes;
    SieveOfE(int LIM) {
        is_p = vector<int>(LIM+10, true);
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
    }
};

SieveOfE sieve(MX);

void solve() {
    cin >> n;
    unordered_map<int, int> pf;
    int tmp = n;
    int i = 0;
    while (tmp > 1 && i < sieve.primes.size()) {
        int prime = sieve.primes[i];
        if (prime * prime > n) break;
        while (tmp % prime == 0) {
            tmp /= prime;
            pf[prime]++;
        }
        i++;
    }
    if (tmp > 1) pf[tmp]++;
    long long ans = 0;
    vector<pair<int,int>> res;
    int mult = 1;
    for (auto &p : pf) {
        res.push_back({p.second, p.first});
        mult *= p.first;
    }
    sort(res.begin(), res.end());
    int prev = 0;
    for (auto r : res) {
        ans += mult * (r.first - prev);
        prev = r.first;
        mult /= r.second;
    }
    cout << ans << '\n';
}

/*

*/







