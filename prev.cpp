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
 
const LL MX = 5 * 1e7;
const LL MOD = 1000000007;
const LL K = 27;
 
struct Vertex {
    LL next[K];
    bool end = false;
 
    Vertex() {
        fill(next, next+K, -1);
    }
};
 
LL n, dp[MX];
string a;
vector<Vertex> trie(1);
 
void add_string(string const& s) {
    LL v = 0;
    for (char ch : s) {
        LL c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].end = true;
}
 
/*
 
*/
void debug() {
    cout << "dp: ";
    for (LL i = 0; i <= a.size(); i++) {
        cout << dp[i] << ' ';
    }
    cout << endl;
}
 
void solve() {
    cin >> a;
    cin >> n;
    string tmp;
    for (LL i = 0; i < n; i++) {
        cin >> tmp;
        add_string(tmp);
    }
    LL N = a.size();
    dp[N] = 1;
    for (LL i = N-1; i >= 0; i--) {
        LL v = 0;
        //cout << "SUS " << a.substr(i) << endl;
        LL j = i;
        for (LL j = i; j < N; j++) {
            LL c = a[j] - 'a';
            v = trie[v].next[c];
            if (v == -1) break;
            if (trie[v].end) {
                //cout << "ended on: " << ch << endl;
                //cout << "ch " << ch << " and " << i << " dp[i+1] " << dp[i+1] << " j: " << j << " " << dp[j+1] << endl;
                dp[i] += dp[j+1];
                dp[i] %= MOD;
            }
        }
        //dp[i] += ans;
    }
    //debug();
    cout << dp[0] << endl;
}
 
 
