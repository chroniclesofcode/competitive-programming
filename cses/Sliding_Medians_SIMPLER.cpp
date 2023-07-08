#include <bits/stdc++.h>

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
#define NINF -INF

const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

int n, k, a[MX];
multiset<int> s1, s2;
/*
   FOR SOME REASON CSES gives Runtime error, I cannot find the error
   but on my machine it compiles properly and gives all correct solutions.

   In the repo, find the Sliding_Medians which is more complex, that runs
   without issues. This one is just simpler logic.
*/

void add_set(int v) {
    int l = *s1.rbegin();
    if (v > l) {
        s2.insert(v);
        if (s2.size() > s1.size()) {
            s1.insert(*s2.begin());
            s2.erase(s2.find(*s2.begin()));
        }
    } else {
        s1.insert(v);
        if (s1.size() > s2.size()) {
            int u = *s1.rbegin();
            s2.insert(u);
            s1.erase(s1.find(u));
        }
    }
}

void rem_set(int v) {
    if (!s1.empty() && v <= *s1.rbegin()) {
        s1.erase(s1.find(v));
    } else {
        s2.erase(s2.find(v));
    }
}

int medi() {
    if (s1.size() == s2.size()) {
        return *s1.rbegin();
    } else if (s1.size() > s2.size()) {
        return *s1.rbegin();
    } else {
        return *s2.begin();
    }
}

void debug() {
    cout << "s1: ";
    for (auto &e : s1) {
        cout << e << ' '; 
    }
    cout << "s2: ";
    for (auto &e : s2) {
        cout << e << ' ';
    }
    cout << endl;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    s1.insert(a[0]);
    for (int i = 1; i < k; i++) {
        add_set(a[i]);
    }
    cout << medi() << ' ';
    for (int i = k; i < n; i++) {
        debug();
        rem_set(a[i-k]);
        add_set(a[i]);
        cout << medi() << ' ';
    }
    debug();
    cout << endl;
}





