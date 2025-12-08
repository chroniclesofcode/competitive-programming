class SieveOfE {
public:
    vector<int> is_p;
    vector<int> primes;
    SieveOfE(int LIM) {
        is_p = vector<int>(LIM+10, true);
        is_p[0] = is_p[1] = false;
        for (int i = 2; i*i <= LIM; i++) {
            if (is_p[i]) {
                for (int j = i*i; j <= LIM; j += i) {
                    is_p[j] = false;
                }
            }
        }
        for (int i = 2; i <= LIM; i++) {
            if (is_p[i]) primes.push_back(i);
        }
    }
};

class Solution {
public:
    int largestPrime(int n) {
        SieveOfE sieve(n);
        vector<int> &p = sieve.primes;
        int tot = 0;
        int ans = 2;
        for (int i = 0; i < p.size(); i++) {
            tot += p[i];
            if (tot > n) break;
            if (sieve.is_p[tot]) {
                ans = tot;
            }
        }
        return ans;
    }
};