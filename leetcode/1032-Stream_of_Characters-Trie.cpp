class Trie {
public:
    class Node {
    public:
        bool end = false;
        int a[26] = {0};
    };
    vector<Node> nodes;
    Trie() {
        nodes.push_back(Node());
    }

    void add(const std::string& s) {
        int n = s.size();
        int v = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (nodes[v].a[c] > 0) {
                v = nodes[v].a[c];
            } else {
                nodes[v].a[c] = nodes.size();
                nodes.push_back(Node());
                v = nodes.size() - 1;
            }
        }
        nodes[v].end = true;
    }
};
class StreamChecker {
public:
    Trie t;
    std::string str;
    StreamChecker(vector<string>& words) {
        for (auto& w : words) {
            reverse(w.begin(), w.end());
            t.add(w);
        }
    }
    
    bool query(char letter) {
        str.push_back(letter);
        int n = str.size();
        int v = 0;
        for (int i = n-1; i >= 0; i--) {
            int c = str[i] - 'a';
            if (t.nodes[v].a[c] > 0) {
                v = t.nodes[v].a[c];
            } else {
                break;
            }
            if (t.nodes[v].end) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
