class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        #define LL long long
        long long res = 0;
        long long at = a, bt = b;
        for (int i = n-1; i >= 0; i--) {
            if (at & ((LL)1 << i)) at ^= (LL)1 << i;
            if (bt & ((LL)1 << i)) bt ^= (LL)1 << i;
        }
        for (int i = n-1; i >= 0; i--) {
            long long shift = (LL)1 << i;
            at |= (a & shift);
            bt |= (b & shift);
            if (a & shift && b & shift) {
                continue;
            } else if (a & shift && !(b & shift)) {
                if ((bt^res) < (at^res)) {
                    res |= shift;
                }
            } else if (!(a & shift) && b & shift) {
                if ((at^res) < (bt^res)) {
                    res |= shift;    
                }
                
            } else if (!(a & shift) && !(b & shift)) {
                res |= shift;
            }

        }
        
        int md = (int)1e9 + 7;
        return (((a^res) % md) * ((b^res) % md)) % md;
    }
};
