class Solution {
public:
    double myPow(double x, int n) {
        double elem = 1;
        double run = x;
        int neg = n < 0;
        n = abs(n);
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                elem *= run;
                cout << "ith bit ran " << i << '\n';
            }
            run *= run;
        }
        if (neg) {
            elem = 1.0 / elem;
        }
        return elem;
    }
};
/*
    n = 2^0*bit1 + 2^1*bit2 etc...
    x^n = x^(2^0+2^3+2^5)
    x^n = x^2^0 * x^2^3 * x^2^5

    1010
*/
