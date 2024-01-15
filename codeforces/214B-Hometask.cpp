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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans;
    bool flag = false;
    int tot = 0;
    int threecount = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            ans.push_back(0);
            flag = true;
        } else if (a[i] == 3) {
            threecount++;
        }
        tot += a[i];
    }
    if (!flag) {
        cout << "-1\n"; return;
    }
    sort(a.begin(), a.end());
    a.erase(remove(a.begin(), a.end(), 0), a.end());
    if (a.size() == 0 && ans.size() > 0) {
        cout << 0 << '\n';
        return;
    }
    if (tot % 3 == 0) {
        for (auto e : a) {
            ans.push_back(e);
        }
    } else {
        int md = tot % 3;
        bool fl = false, fl2 = false;
        unordered_map<int, int> mp;
        int ret1 = -1, ret21 = -1, ret22 = -1;
        n = a.size();
        int target = md;
        for (int i = 0; i < n; i++) {
            int val = a[i]%3;
            if (val == target) {
                fl = true;
                ret1 = val;
                break;
            }
            if (fl2 == false && mp[target-val]) {
                fl2 = true;
                ret21 = val;
                ret22 = target-ret21;
            } else if (fl2 == false && mp[3+target-val]) {
                fl2 = true;
                ret21 = val;
                ret22 = 3+target-val;
            }
            mp[val] = 1;
        }
        if (!flag) {
            cout << "0\n"; return;
        }
        if (fl) {
            for (int i = 0; i < n; i++) {
                if (a[i]%3 == ret1) {
                    ret1 = -1;
                    continue;
                }
                ans.push_back(a[i]);
            }
        } else if (fl2) {
            for (int i = 0; i < n; i++) {
                if (a[i]%3 == ret21) {
                    ret21 = -1;
                    continue;
                }
                if (a[i]%3 == ret22) {
                    ret22 = -1;
                    continue;
                }
                ans.push_back(a[i]);
            }
        } else {
            cout << "0\n";
            return;
        }
    }
    int onlyzero = true;
    for (auto e : ans) {
        if (e != 0) onlyzero = false;
    }
    if (onlyzero) {
        cout << 0 << '\n';
        return;
    }
    for (int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << '\n';
}

/*

*/



