class Solution {
public:
    /*
       Upon inspection, it's fairly clear that you set +color on the left, and -color on the right, then when you take the cumulative sum of this array, you will have the sum of all mixed colors for every single element (note the bounds of [l,r) allow this, if it was larger you would have to use a map solution instead of an array-based solution).

I then tried to check if sum[i] != sum[i-1], if this holds, then we can add it to ans. However, this does not take into account when 2 colors add to the same sum. I was thinking of a map based approach, but wasn't really satisfied with the logn overhead. So I decided to use a rolling hash, since even if two numbers add to the same thing, their hash will be different. So I set hash[l] and hash[r] to be the negative, and took the cumulative sum. I checked if hash[l] != hash[l-1] and if this doesn't hold, we add the original sum[i-1] to ans. Anyways, the details are in the code - there's a lot of extra stuff as well.

Also, theoretically there could be a test case this code fails for, since the hash function might provide a collision for two numbers, but this is incredibly unlikely for something of this size.

    */
    long long seg[(int)1e5+1];
    long long hash[(int)1e5+1];
    long long p[(int)1e5+1];
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = segments.size();
        int mx = 0;

        for (int i = 0; i < (int)1e5+1; i++) {
            p[i] = 1;
        }
        int m = 1e9+9;
        int pp = 31;
        
        for (int i = 0; i < n; i++) {
            int l = segments[i][0];
            int r = segments[i][1];
            int c = segments[i][2];
            seg[l] += c;
            seg[r] -= c;
            p[l] *= pp;
            p[l] %= m;
            int addval = ((c + 1) * p[l]) % m; 
            hash[l] = (hash[l] + addval) % m;
            hash[r] = (hash[r] - addval) % m;

            mx = max(mx, r);
        }
        for (int i = 2; i < mx; i++) {
            seg[i] += seg[i-1];
            hash[i] += hash[i-1];
            if (hash[i] < 0) hash[i] = (hash[i] + m) % m;
        }
        
        vector<vector<long long>> ans;
        int beg = hash[1] <= 0 ? 2 : 1;
        for (int i = 2; i <= mx; i++) {
            if (hash[i] != hash[i-1] && hash[i-1] > 0) {
                ans.push_back({beg, i, seg[i-1]});
                beg = i;
            }
            if (hash[i] <= 0) {
                beg = i+1;
            }
        }
        return ans;
    }
};
