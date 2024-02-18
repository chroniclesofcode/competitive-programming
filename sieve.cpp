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
    constexpr int LIM = (int)1e5;
    vector<int> is_p(LIM, true);
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
    return;
}

/*
   ["a","aba","ababa","aa"]
["pa","papa","ma","mama"]
["abab","ab"]
["a","a"]
["bcc","c","cbaaa","ba","cabbc","b","bcbb","baca","caa","aa","caa","ca","cacac"]
*/




