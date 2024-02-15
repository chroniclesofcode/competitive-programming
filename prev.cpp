class Solution {
public:
    int ct[26];
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> sz;
        for (int i = 0; i < words.size(); i++) {
            sz.push_back(words[i].size());
            for (auto c : words[i]) {
                ct[(int)c - 'a']++;
            }
        }
        sort(sz.begin(), sz.end());
        int ans = 0;
        for (auto e : sz) {
            bool oned = false;
            if (e % 2 == 1) {
                for (int i = 0; i < 26; i++) {
                    if (ct[i] % 2 == 1) {
                        e--;
                        ct[i]--;
                        oned = true;
                        break;
                    }
                }
            }
            for (int i = 0; i < 26; i++) {
                if (ct[i] == 0) continue;
                if (e % 2 == 1 && !oned) {
                    ct[i]--;
                    e--;
                    oned = true;
                }
                int reduce = 2*(ct[i]/2);
                if (reduce >= e) {
                    ct[i] -= e;
                    e = 0;
                } else {
                    e -= reduce;
                    ct[i] -= reduce;
                }
                if (e == 0) break;
            }
            if (e == 0) {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};
