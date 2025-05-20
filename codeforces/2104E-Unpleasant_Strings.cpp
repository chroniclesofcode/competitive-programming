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

void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    cin >> q;
    vector<string> t(q);
    for (int i = 0; i < q; i++) {
        string tmp; cin >> tmp;
        t[i] = std::move(tmp);
    }
    vector<vector<int>> idx(k, vector<int>());
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        idx[c].push_back(i);
    }
    vector<int> min_k(n+1);
    // vector<int> k_ct(k);
    vector<int> k_dp(k, 1);
    vector<int> curr_dp(k, 0);
    min_k[n] = 1;
    for (int i = n-1; i >= 0; i--) {
        int c = s[i] - 'a';
        // k_ct[c]++;
        // for (int j = 0; j < k; j++) {
        //     ret = min(ret, k_ct[j]);
        // }
        int ret = k_dp[0] + 1;
        for (int j = 0; j < k; j++) {
            if (j == c) {
                curr_dp[j] = 1 + min_k[i+1];
            } else {
                curr_dp[j] = k_dp[j];
            }

            ret = min(ret, curr_dp[j]);
        }
        min_k[i] = ret;
        swap(curr_dp, k_dp);
    }
    // for (int i = 0; i < k; i++) {
    //     cout << "idx " << i << " : ";
    //     for (int j = 0; j < idx[i].size(); j++) {
    //         cout << idx[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << "min_k: ";
    // for (int i = 0; i < n; i++) {
    //     cout << min_k[i] << ' ';
    // }
    // cout << endl;
    for (int i = 0; i < q; i++) {
        int sz = t[i].size();
        int curr = -1;
        int did_end = 0;
        for (int j = 0; j < sz; j++) {
            int c = t[i][j] - 'a';
            auto it = upper_bound(idx[c].begin(), idx[c].end(), curr);
            if (it == idx[c].end()) {
                did_end = 1;
                break;
            }
            curr = *it;
        }
        int ans = 0;
        if (did_end) {
            ans = 0;
        } else if (curr == n-1) {
            ans = 1;
        } else { 
            ans = min_k[curr+1];
        }
        cout << ans << '\n';
    }
}

/*
    Use a k-pointer method to find out the last element of
    each string which matches the original string s. Such that
    from this pointer p onwards, p cannot be any the characters
    afterwards in s. So every string will have a point in the
    OG string that it corresponds to, and the minimum characters
    needed such that it stops being a subsequence is:
    0 if it's at the end
    1 if there is a letter unused in the string, else
    min(char count after p) + 1, so basically we need to find the
    minimum count after p, and add that many, then add 1 to break it
    from the subsequence. How do we do this?
    we can just do it straight up by keeping a cache array from the 
    end which gives the minimum pretty much.

25 3

acaacaabbcbacbcbbaacaaaba
1
cabb

meant to be 4
*/