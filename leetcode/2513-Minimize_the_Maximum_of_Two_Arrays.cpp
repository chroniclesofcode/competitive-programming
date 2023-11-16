class Solution {
public:
    #define LL long long
    int minimizeSet(int div1, int div2, int uq1, int uq2) {
        LL lo = uq1 + uq2;
        LL hi = INT_MAX;
        LL ans = INT_MAX;
        while (lo <= hi) {
            LL mid = lo + (hi - lo)/2;
            LL p1 = mid / div1; // not allowed
            LL p2 = mid / div2; // not allowed
            LL both = p1==0||p2==0 ? 0 : mid / (((LL)div1*div2) / __gcd(div1,div2) );
            LL onlydivs = p1 + p2 - both;
            LL nop1 = (onlydivs-p1), nop2 = (onlydivs-p2);
            LL a1 = max(uq1 - nop1, (LL)0); // no p1
            LL a2 = max(uq2 - nop2, (LL)0); // no p1
            LL numbersleft = mid - onlydivs;
            bool flag = numbersleft >= a1 + a2;
            if (flag) {
                cout << "true!\n";
                ans = min(ans, mid);
                hi = mid-1;
            } else lo = mid+1;
        }
        return ans;
    }
};
