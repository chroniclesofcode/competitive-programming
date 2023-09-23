class Solution {
public:
    int mark[1001], dp[1001], last[1001];
    string smallestSubsequence(string s) {
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            last[ch] = i;
            dp[ch] = -1;
        }
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            // Unmarked, auto-add it
            if (dp[ch] == -1) {
                mark[i] = 1;
                dp[ch] = i;
                continue;
            }
            // Check if we need to swap
            for (int j = dp[ch]+1; j < i; j++) {
                if (!mark[j]) continue;
                int cr = s[j] - 'a';
                if (cr < ch) {
                    // Lower char found
                    mark[dp[ch]] = 0;
                    mark[i] = 1;
                    dp[ch] = i;
                    break;
                } else if (last[cr] < i) {
                    break;
                }
            }
        }
        string ret;
        cout << endl;
        for (int i = 0; i < s.size(); i++) {
            if (mark[i]) ret += s[i];
        }
        cout << endl;
        return ret;
    }
};
