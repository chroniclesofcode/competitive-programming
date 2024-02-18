class Solution {
public:
    struct hashes {
        int base, inv, mod, sz;
        vector<long long> powers = {1}, invpowers = {1}, psa = {0};

        hashes(string s, int m = 1000000007, int b = 131) {
            sz = s.size();
            base = b;
            mod = m;

            inv = 1;
            long long cur = base;
            int exp = m - 2;
            for (int exp=m-2; exp; exp>>=1) {
                if (exp&1) inv = inv * cur % m;
                cur = cur * cur % m;
            }

            for (int i=0; i<s.size(); i++) {
                powers.push_back(powers.back()*base%mod);
                invpowers.push_back(invpowers.back()*inv%mod);
                psa.push_back((psa.back()+s[i]*powers[i])%mod);
            }
        }

        hashes() {}

        long long get(int l, int r) {
            return (psa[r+1]-psa[l]+mod)*invpowers[l]%mod;
        }
    };
    long long countPrefixSuffixPairs(vector<string>& words) {
        unordered_map<long long, int> m;
        long long ans = 0;
        for (int i = 0; i < words.size(); i++) {
            hashes hash(words[i]);
            int n = words[i].size();
            for (int j = 0; j < words[i].size(); j++) {
                int pref = hash.get(0, j);
                int suf = hash.get(n-1-j, n-1);
                if (pref == suf) ans += m[pref];
            }
            m[hash.get(0, n-1)]++;
        }
        return ans;
    }
};
