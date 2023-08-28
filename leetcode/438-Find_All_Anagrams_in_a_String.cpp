class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> exist;
        for (char ch : p) {
            exist[ch]++;
        }
        int j = 0;
        unordered_map<char, int> ct;
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (exist[ch] == 0) {
                // Doesn't exist in our pattern, we reset our list.
                j = i+1;
                ct.clear();
            } else if (exist[ch] == ct[ch]) {
                // We have hit our quota, need to shrink the list.
                ct[ch]++;
                while (s[j] != ch) {
                    ct[s[j]]--;
                    j++;
                }
                ct[s[j]]--;
                j++;
            } else if (exist[ch] > ct[ch]) {
                // We can just add and increment
                ct[ch]++;
            }
            if (i - j + 1 == p.size()) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};
