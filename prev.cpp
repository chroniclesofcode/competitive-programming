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
    int t; cin >> t;
    while (t--)
        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

class SieveOfE {
public:
    vector<int> is_p;
    vector<int> primes;
    SieveOfE(int LIM) {
        is_p = vector<int>(LIM, true);
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

SieveOfE sieve((int)1e7+1);

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tot = 0;
    unordered_map<int,int> ps;
    for (int i = 0; i < n; i++) {
        int tmp = a[i];
        int j = 0;
        while (tmp > 1) {
            if (tmp % sieve.primes[j] == 0) {
                tmp /= sieve.primes[j];
                ps[sieve.primes[j]]++;
                tot++;
            } else {
                j++;
            }
        }
    }
    int ans = 0;
    for (auto& e : ps) {
        ans += e.second / 2;
        tot -= 2*(e.second/2);
    }
    ans += tot/3;
    cout << ans << '\n';
}

/*
    2 sames can make 1. 3 diffs can make 1.
*/





