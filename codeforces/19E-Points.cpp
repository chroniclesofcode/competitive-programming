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

const LL MX = 2*1e6 + 5;
LL n;

LL com[MX];
LL x[MX];
LL y[MX];

set<LL> pts[MX];
LL sz;
LL t[MX];

vector<LL> s;

// bugs: 2*1e5 + 5 not large enough for my arrays for some reason????

void update(LL p, LL v, LL i = 1, LL cL = 0, LL cR = sz) {
    if (cR - cL == 1) {
        t[i] = max(t[i], v);
        return;
    }
    LL mid = (cL + cR) / 2;
    if (p < mid) update(p, v, i * 2, cL, mid);
    else update(p, v, i * 2 + 1, mid, cR);
    t[i] = max(t[i*2], t[i*2+1]);
}

void removal(LL p, LL v, LL i = 1, LL cL = 0, LL cR = sz) {
    if (cR - cL == 1) {
        t[i] = v;
        return;
    }
    LL mid = (cL + cR) / 2;
    if (p < mid) removal(p, v, i * 2, cL, mid);
    else removal(p, v, i * 2 + 1, mid, cR);
    t[i] = max(t[i*2], t[i*2+1]);
}

LL query(LL p, LL k, LL i = 1, LL cL = 0, LL cR = sz) {
    if (k >= t[i]) {
        return -1;
    }
    if (cR - cL == 1) {
        return cL;
    }
    LL mid = (cL + cR) / 2;
    if (p >= mid) {
        return query(p, k, i*2+1, mid, cR);
    } else {
        LL ans = query(p, k, i*2, cL, mid);
        if (ans >= p) {
            return ans;
        } else {
            return query(p, k, i*2+1, mid, cR);
        }
    }
    return -1;
}



void debug(LL inp = n) {
    cout << "start" << endl;
    for (LL i = 0; i < inp; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}

void debug2(LL inp) {
    cout << "tree" << endl;
    for (LL i = 0; i < 4*inp; i++) {
        cout << t[i] << " ";
    }   
    cout << endl;
}

void solve() {
    cin >> n;
    for (LL i = 0; i < n; i++) {
        string str;
        LL a, b;
        cin >> str >> a >> b;
        x[i] = a;
        y[i] = b;
        if (str == "add") {
            com[i] = 1;
        } else if (str == "remove") {
            com[i] = 2;
        } else if (str == "find") {
            com[i] = 3;
        }
        s.push_back(x[i]);
    }
    sort(s.begin(), s.end());
    auto send = unique(s.begin(), s.end());
    sz = send - s.begin();
    //debug(sz);

    for (LL i = 0; i < n; i++) {
        // Finds x[i] in s
        auto it = lower_bound(s.begin(), s.begin()+sz, x[i]);
        LL idx = it - s.begin();
        //debug2(sz);
        if (com[i] == 1) {
            // add
            //cout << "insert " << idx << " " << y[i] << endl;
            pts[idx].insert(y[i]);
            update(idx, y[i]);
        } else if (com[i] == 2) {
            // remove
            //cout << "erase " << idx << " " << y[i] << endl;
            pts[idx].erase(pts[idx].find(y[i]));
            if (pts[idx].size() == 0) {
                removal(idx, 0);
            } else {
                removal(idx, *(pts[idx].rbegin()));
            }
        } else if (com[i] == 3) {
            // find
            LL ret = query(idx+1, y[i]);
//            cout << "RETRETRETRETRET: " << ret << endl;
            if (ret == -1 || ret < idx+1 || ret >= sz) {
                cout << -1 << '\n';
                continue;
            }
            LL ans = *(pts[ret].upper_bound(y[i]));
            cout << s[ret] << " " << ans << '\n';

        }
    }
}

