class Solution {
public:
    int n;
    string target;
    int ans = INT_MAX;
    void bt(string& s, int start, int ct) {
        if (start > n) return;
        if (ct >= n+3) return;
        if (start == n) { 
            if (s == target)
                ans = min(ans, ct);
            return;
        }
        if (s[start] == target[start]) {
            bt(s, start+1, ct);
            return;
        }

        for (int j = start+1; j < n; j++) {
            if (s[j] == target[start] && s[j] != target[j]) {
                swap(s[start], s[j]);
                bt(s, start+1, ct+1);
                swap(s[start], s[j]);
            }
        }
    }
    int kSimilarity(string s1, string s2) {
        n = s1.size();
        target = s2;
        bt(s1, 0, 0);
        return ans;
    }
};
