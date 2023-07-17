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
const int K = 26;

struct Vertex {
    int next[K];
    bool end = false;

    Vertex() {
        fill(next, next+K, -1);
    }
};

int n;
vector<Vertex> trie(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].end = true;
}

// Find if there is an entry in trie for s[l..r]
bool search(string const& s, int l, int r) {
    int v = 0;
    for (int i = l; i <= r; i++) {
        char ch = s[i];
        int c = ch - 'a';
        v = trie[v].next[c];
        if (v == -1) {
            return true;
        }
        if (trie[v].end == true) {
            return false;
        }
    }
    return true;
}
    

/*

*/

void solve() {

}





