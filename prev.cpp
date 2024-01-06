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

vector<string> gd(string &s) {
    int sz = s.size();
    vector<string> ret;
    for (int i = 0; i < sz/2; i++) {
        if (sz % (i+1) == 0) {
            string pref = s.substr(0, i+1);
            bool flag = true;
            for (int j = i+1; j < sz; j += i+1) {
                if (pref != s.substr(j, i+1)) {
                    flag = false; break;
                }
            }
            if (flag) {
                ret.push_back(pref);
            }
        }
    }
    ret.push_back(s);
    return ret;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() == s2.size() && s1 == s2) {
        vector<string> ans = gd(s1);
        cout << ans.size() << '\n';
        return;
    }
    vector<string> d1 = gd(s1);
    vector<string> d2 = gd(s2);
    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());
    vector<string> ans;
    set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), back_inserter(ans));
    cout << ans.size() << '\n';
}

/*

*/



