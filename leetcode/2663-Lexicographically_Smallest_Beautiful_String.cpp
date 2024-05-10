class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        string ans = "";
        int n = s.size();
        vector<string> loops = { "abc", "acb", "bac", "bca", "cab", "cba" };
        for (int i = n-1; i >= 0; i--) {
            int c = s[i] - 'a';
            if (c == 'z'-'a') continue;
            int tofill = n-1-i;
            if (tofill >= 3 && k <= 2) break;
            for (int j = c+1; j < k; j++) {
                if (i > 0 && j == s[i-1]-'a') continue;
                if (i > 1 && j == s[i-2]-'a') continue;
                int idx = 0;
                for (; idx < loops.size(); idx++) {
                    if (loops[idx][0]-'a' == j) continue;
                    if (i > 0 && loops[idx][0] == s[i-1]) continue;
                    if (tofill >= 2 && loops[idx][1]-'a' == j) continue;
                    break;
                }
                if (idx == loops.size()) continue;
                int start = 0;
                ans = s.substr(0, i);
                ans.push_back((char)(j+'a'));
                for (int i = 0; i < tofill; i++) {
                    ans.push_back(loops[idx][start]);
                    start = (start + 1) % 3;
                }
                return ans;
            }
        }
        return ans;
    }
};
