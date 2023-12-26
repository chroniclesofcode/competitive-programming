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

void solve() {
    constexpr int LIM = 100000;
    vector<int> is_p(LIM, true);
    vector<int> primes;
    is_p[0] = is_p[1] = false;
    for (int i = 2; i < LIM; i++) {
        if (is_p[i]) {
            primes.push_back(i);
            if ((LL)i*i < LIM) {
                for (int j = i*i; j <= LIM; j += i) {
                    is_p[j] = false;
                }
            }
        }
    }
    return;
}

/*

*/




