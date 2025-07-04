#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k, q;
int ans = 0;
int ch(char c) {
    return (c - '0');
}

void cost(string s, vector<int> costs) {
    int sz = s.size();
    if (sz == 1) {
        ans = costs[0];
        return;
    }
    string ret;
    vector<int> nextcosts;
    for (int i = 0; i < sz; i+= 3) {
        int ct = ch(s[i])+ch(s[i+1])+ch(s[i+2]);
        bool is_one = true;
        int quota_rm = 0;
        if (ct == 0 || ct == 3) quota_rm = 2;
        else quota_rm = 1;
        if (ct >= 2) {
            ret.push_back('1');
        } else {
            ret.push_back('0');
            is_one = false;
        }
        vector<int> amt;
        for (int j = 0; j < 3; j++) {
            if (s[i+j] == '1' && is_one) {
                amt.push_back(costs[i+j]);
            } else if (s[i+j] == '0' && !is_one) {
                amt.push_back(costs[i+j]);
            }
        }
        sort(amt.begin(), amt.end());
        if (quota_rm == 2) {
            nextcosts.push_back(amt[0]+amt[1]);
        } else {
            nextcosts.push_back(amt[0]);
        }
    }
    cost(ret, nextcosts);
}

void solve() {
    cin >> n;
    std::string s;
    cin >> s;
    vector<int> costs(s.size(), 1);
    cost(s, costs);
    cout << ans << '\n';
}

/*

*/

