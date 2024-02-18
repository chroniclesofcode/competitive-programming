#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

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

struct hashes {
    int base, inv, mod, sz;
    vector<long long> powers = {1}, invpowers = {1}, psa = {0};

    hashes(string s, int m = 1000000007, int b = 131) {
        sz = s.size();
        base = b;
        mod = m;

        inv = 1;
        long long cur = base;
        int exp = m - 2;
        for (int exp=m-2; exp; exp>>=1) {
            if (exp&1) inv = inv * cur % m;
            cur = cur * cur % m;
        }

        for (int i=0; i<s.size(); i++) {
            powers.push_back(powers.back()*base%mod);
            invpowers.push_back(invpowers.back()*inv%mod);
            psa.push_back((psa.back()+s[i]*powers[i])%mod);
        }
    }

    hashes() {}
    
    long long get(int l, int r) {
        return (psa[r+1]-psa[l]+mod)*invpowers[l]%mod;
    }
};

void solve() {

}

/*

*/



