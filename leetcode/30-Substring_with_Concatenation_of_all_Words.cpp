class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int wsz = words[0].size();
        vector<int> ans;
        unordered_map<string, int> exists;
        int allsz = words.size();
        for (const auto& word : words) {
            exists[word]++;
        }
        for (int st = 0; st < wsz; st++) {
            int j = st;
            int tot = 0;
            unordered_map<string, int> mark;
            for (int i = st; i < n; i += wsz) {
                auto it = exists.find(s.substr(i, wsz));
                if (it != exists.end()) {
                    const std::string& str = it->first;
                    int req = it->second;
                    mark[str]++;
                    tot++;
                    while (j < n && mark[str] > req) {
                        tot--;
                        mark[s.substr(j, wsz)]--;
                        j += wsz;
                    }
                    if (tot == allsz) {
                        ans.push_back(i-(allsz-1)*wsz);
                    }
                } else {
                    while (j < i) {
                        tot--;
                        mark[s.substr(j, wsz)]--;
                        j += wsz;
                    }
                    j += wsz;
                }
            }
        }
        return ans;
    }
};
