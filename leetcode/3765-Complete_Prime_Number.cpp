class Solution {
public:
    bool check_prime(int x) {
        if (x == 1) return false;
        int mx = sqrt(x);
        for (int i = 2; i <= mx; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    bool completePrime(int num) {
        int n = num;
        int ct = 0;
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n%10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        int val = 0;
        for (int i = 0; i < digits.size(); i++) {
            val += digits[i];
            if (!check_prime(val)) return false;
            val *= 10;

            int rval = 0;
            for (int j = i; j < digits.size(); j++) {
                rval += digits[j];
                if (j != digits.size()-1)
                    rval *= 10;
            }
            if (!check_prime(rval)) return false;
        }

        return true;
    }
};
/*
*/