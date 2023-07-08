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

LL n, k, a[MX], sum1, sum2;
multiset<LL> s1, s2;
/*

*/

void add_set(LL v) {
    if (s1.empty() && s2.empty()) {
        s2.insert(v);
        sum2 += v;
    } else if (!s2.empty() && v >= *s2.begin()) {
        sum2 += v;
        s2.insert(v);
        if (s2.size() > s1.size()) {
            sum1 += *s2.begin();
            sum2 -= *s2.begin();
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
    } else if (!s2.empty() && v <= *s2.begin()) {
        sum1 += v;
        s1.insert(v);
        if (s1.size() > s2.size()) {
            sum2 += *s1.rbegin();
            sum1 -= *s1.rbegin();
            s2.insert(*s1.rbegin());
            s1.erase(s1.find(*s1.rbegin()));
        }
    } else if (!s1.empty() && v >= *s1.rbegin()) {
        sum2 += v;
        s2.insert(v);
        if (s2.size() > s1.size()) {
            sum1 += *s2.begin();
            sum2 -= *s2.begin();
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
    } else if (!s1.empty() && v <= *s1.rbegin()) {
        sum1 += v;
        s1.insert(v);
        if (s1.size() > s2.size()) {
            sum2 += *s1.rbegin();
            sum1 -= *s1.rbegin();
            s2.insert(*s1.rbegin());
            s1.erase(s1.find(*s1.rbegin()));
        }
    }
}

void rem_set(LL v) {
    if (!s1.empty() && v <= *s1.rbegin()) {
        s1.erase(s1.find(v));
        sum1 -= v;
    } else {
        s2.erase(s2.find(v));
        sum2 -= v;
    }
}

LL medi() {
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
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    sum1 = sum2 = 0;
    for (LL i = 0; i < k; i++) {
        add_set(a[i]);
    }
    LL me = medi();
    cout << (me*s1.size()-sum1)+(sum2-me*s2.size()) << ' ';
    for (LL i = k; i < n; i++) {
        rem_set(a[i-k]);
        add_set(a[i]);
        me = medi();
        cout << (me*s1.size()-sum1)+(sum2-me*s2.size()) << ' ';
    }
    cout << endl;
}





