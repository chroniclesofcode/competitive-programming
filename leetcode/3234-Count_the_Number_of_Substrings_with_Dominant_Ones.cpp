class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> z;
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') z.push_back(i);
            else ones++;
        }
        int N = sqrt(ones);
        int sz = z.size();
        if (sz == 0) {
            return n * (n+1) / 2;
        }
        int ans = 0;
        for (int k = 0; k <= N; k++) {
            int j = 0;
            int target = k*k;
            int zct = 0;
            int oct = 0;
            int idx = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') zct++;
                else oct++;
                while (zct > k) {
                    if (s[j] == '0') {
                        idx++;
                        zct--;
                    } else oct--;
                    j++;
                }
                if (zct == k && oct >= target) {
                    int surplus = oct - target;
                    int add = 1;
                    if (k == 0) add = surplus;
                    else add += min(surplus, z[idx] - j);
                    ans += add;
                }
            }
        }
        return ans;
    }
};
/*
 5 elems
 0 1 2 3z 4
 at 3z. 5 - 3 - 1 ones left.
 the question becomes -> 
 given two integers x,y - how many ways can you take req 
 or MORE integers from both x,y. Note: you can also take
 it completely from one side or another. In O(1).

*/
