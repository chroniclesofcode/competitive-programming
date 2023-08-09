class Solution {
public:
    /*
       Very straightforward question. Just remember a ranges question
       is 99% chance is a greedy sort on intervals. My method is
       very unconventional, we just greedily set each slot as taken
       or not taken, and we sort by length, so the longest will 
       be taken first. Honestly not a good solution. A better solution
       is to just use DP

       for each tap
       iterate over the range of the tap
       set the min for each elem as
       min(dp[i], dp[tapstart] + 1) because we can find the shortest
       time to reach the beginning of the tap, then +1 as a dp sol.

        Another way is to set the taken array as the length of the
        furthest you can reach, and keep iterating until then, 
        updating the furthest as you go.
    */
    int taken[(int)1e4+5];
    int minTaps(int n, vector<int>& ranges) {
        #define arr array<int,4>
        multiset<arr> s;
        for (int i = 0; i < ranges.size(); i++) {
            if (ranges[i] == 0) continue;
            int l = max(0,i - ranges[i]);
            int r = min(n,i + ranges[i]);
            s.insert({l, l-r, r, i+1});
        }
        int ct = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            int l = (*it)[0];
            int r = (*it)[2];
            ct = (*it)[3];
            //ct++;
            if (taken[min(n,r)] != 0) continue;
            int start = taken[max(0,l)];
            for (int i = max(0,l); i < min(n,r); i++) {
                if (taken[i] == 0 || (l >= 1 && taken[l-1] != start)) {
                    taken[i] = ct;
                } else if (taken[i] != start) {
                    taken[i] = ct;
                }
            }
        }
        if (taken[0] == 0) {
            return -1;
        }
        int ans = 1;
        //cout << taken[0] << ' ';
        for (int i = 1; i < n; i++) {
            //cout << taken[i] << ' ';
            if (taken[i] == 0) return -1;
            if (taken[i] != taken[i-1]) {
                ans++;
            }
        }
        return ans;
    }
};
