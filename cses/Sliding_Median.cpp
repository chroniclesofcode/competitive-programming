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

*/

void add_set(int v) {
    if (s1.empty() && s2.empty()) {
        s2.insert(v);
    } else if (!s2.empty() && v >= *s2.begin()) {
        s2.insert(v);
        if (s2.size() > s1.size()) {
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
    } else if (!s2.empty() && v <= *s2.begin()) {
        s1.insert(v);
        if (s1.size() > s2.size()) {
            s2.insert(*s1.rbegin());
            s1.erase(s1.find(*s1.rbegin()));
        }
    } else if (!s1.empty() && v >= *s1.rbegin()) {
        s2.insert(v);
        if (s2.size() > s1.size()) {
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
    } else if (!s1.empty() && v <= *s1.rbegin()) {
        s1.insert(v);
        if (s1.size() > s2.size()) {
            s2.insert(*s1.rbegin());
            s1.erase(s1.find(*s1.rbegin()));
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
    for (int i = 0; i < k; i++) {
        add_set(a[i]);
    }
    cout << medi() << ' ';
    for (int i = k; i < n; i++) {
        //debug();
        rem_set(a[i-k]);
        add_set(a[i]);
        cout << medi() << ' ';
    }
    //debug();
    cout << endl;
}





