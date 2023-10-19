class Solution {
public:

    struct Vertex {
        int next[26];
        bool end = false;

        Vertex() {
            fill(next, next+26, -1);
        }
    };

    int n;
    vector<Vertex> trie;

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

    // Note: search returns true if we DONT find it
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

    int longestValidSubstring(string word, vector<string>& forbidden) {
        trie.emplace_back();
        for (auto &str : forbidden) {
            add_string(str);
        }
        n = word.size();
        int j = n-1;
        int ans = 0;
        int i = n-1;
        while (i >= 0) {
            j = i;
            while (j >= 0 && search(word, j, i)) {
                j--;
            }
            ans = max(ans, i - j);
            i = min(i-1, j+9);
        }
        return ans;
    }
};
