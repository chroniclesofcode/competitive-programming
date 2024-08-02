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

int n, m, k;

struct Trie {
    static const int K = 26;
    struct Vertex {
        int next[K];
        bool end = false;
        Vertex() {
            fill(next, next+K, -1);
        }
    };
    vector<Vertex> trie;

    Trie() : trie(1) {}

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
                return false;
            }
            if (i == r && trie[v].end == true) {
                return true;
            }
        }
        return false;
    }
};

struct BitTrie {
    LL BSZ = 63;
    vector<array<int,2>> tr;
    vector<int> c;
    int idx = 1;
    BitTrie(int sz) : tr(sz+1), c(sz+1) {}

    void add_val(LL num, LL val) {
        LL u = 1;
        for (LL i = BSZ; i >= 0; i--) { 
            LL bit = (num >> i) & 1;
            if (!tr[u][bit]) {
                tr[u][bit] = ++idx;
            }
            u = tr[u][bit];
            c[u] += val;
        }
    }
    
    // Modify depending on question - currently max xor of num in trie
    LL get_xor(LL num) {
        LL u = 1;
        LL res = 0;
        for (LL i = BSZ; i >= 0; i--) {
            LL bit = !((num >> i) & 1);
            if (tr[u][bit] && c[tr[u][bit]] > 0) {
                u = tr[u][bit];
                res |= (bit << i);
            } else {
                u = tr[u][!bit];
                res |= (!bit << i);
            }
        }
        return num^res;
    }
};


void solve() {

}

/*

*/




