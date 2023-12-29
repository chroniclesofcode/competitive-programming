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
}

/*

*/






