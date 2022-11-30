#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2

//const LL MX = 1e5+20;
LL n;
vector<int> factors;
unordered_map<int, int> m;

void primefactorize(int x) {
    for (int f = 2; f*f <= x; f++) {
        while (x % f == 0) {
            factors.push_back(f);
            x /= f;
        }
    }
    if (x != 1) factors.push_back(x);
}

void docalc(vector<int> f) {
    int maxi = 0;
    for (int i = 0; i < factors.size(); i++) {
        m[f[i]]++;
        maxi = max(maxi, m[f[i]]);
    }
    int p = 1;
    int ct = 0; // Counts square roots we need
    while (p < maxi) {
        p *= 2;
        ct++;
    }
    int ret = 1;
    bool isEq = true;
    for (auto it = m.begin(); it != m.end(); it++) {
        ret *= it->first;
        if (it->second != p) {
            isEq = false;
        }
    }
    if (!isEq) {
        ct++;
    }
    cout << ret << " " << ct << '\n';
}

// Find all prime factors, make all prime factors have a count
// to the nearest power of 2 so when you spam sqrt you will just
// reach every distinct prime factor multiplied with each other
void solve() {
    cin >> n;
    primefactorize(n);
    docalc(factors);
}



