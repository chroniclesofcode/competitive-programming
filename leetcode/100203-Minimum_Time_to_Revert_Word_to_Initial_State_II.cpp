class Solution {
public:
    vector<int> zf(string &s) {
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
        return z;
    }
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        vector<int> res = zf(word);
        int ct = 0;
        for (int i = k-1; i < n-1; i += k) {
            ct++;
            if (res[i+1] == n-(i+1)) {
                return ct;
            }
        }
        return ct+1;
    }
};
/*
for each segment of k, work out if the suffix is equal
to the prefix. If so, you win -> iterate and return
the first value. To work it out, use zalgo. For every
segment of k, work out if the future is the same.
*/
