class Solution {
public:
    vector<int> z_function(string s, int sz) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        vector<int> ret;
        for (int i = sz; i < z.size(); i++) {
            if (z[i] == sz) {
                ret.push_back(i - (sz+1));
            }
        }
        return ret;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        string tmp = a + '#' + s;
        vector<int> as = z_function(std::move(tmp), a.size());
        string tmp2 = b + '#' + s;
        vector<int> bs = z_function(std::move(tmp2), b.size());
        vector<int> ans;
        for (int i = 0; i < as.size(); i++) {
            auto it = lower_bound(bs.begin(), bs.end(), as[i]);
            if (it != bs.end()) {
                int idx = *it;
                if (abs(idx-as[i]) <= k) {
                    ans.push_back(as[i]);
                    continue;
                }
            }
            if (it != bs.begin()) {
                it--;
                int idx = *it;
                if (abs(idx-as[i]) <= k) {
                    ans.push_back(as[i]);
                    continue;
                }
            }
        }
        return ans;
    }
};
