class Solution {
public:
    using LL = long long;
    unordered_map<LL, pair<LL,LL>> suf;
    int commonp = 53, commonmod = 1e9 + 23;
    vector<int> stringIndices(vector<string>& words, vector<string>& qr) {
        for (int j = 0; j < words.size(); j++) {
            std::string &str = words[j];
            int p = commonp, m = commonmod; 
            long long hash = 0, pp = 1;
            if (suf.find(-1) != suf.end()) {
                suf[-1] = min(suf[-1], {str.size(), j});
            } else {
                suf[-1] = {str.size(), j};
            }
            for (int i = str.size()-1; i >= 0; i--) {
                hash = (hash + (str[i]  - 'a' + 1) * pp) % m;
                if (suf.find(hash) != suf.end()) {
                    suf[hash] = min(suf[hash], { str.size(), j });
                } else {
                    suf[hash] = { str.size(), j };
                }
                pp = (pp * p) % m;
            }
        }
        vector<int> ans;
        for (auto &cur : qr) {
            int p = commonp, m = commonmod;
            long long hash = 0, pp = 1;
            int ret = suf[-1].second;
            for (int i = cur.size() - 1; i >= 0; i--) {
                hash = (hash + (cur[i]-'a'+1) * pp) % m;
                pp = (pp * p) % m;
                if (suf.find(hash) != suf.end()) {
                    ret = suf[hash].second;
                } else {
                    break;
                }
            }
            ans.push_back(ret);
        }
        return ans;
    }
};
