class Solution {
public:
    /*
       I... failed this one. In my opinion, it's actually pretty
       easy, I just got stuck down one path for too long. I tried
       to do a sorting on the nearest dry patch for each element that
       would get overflown, but there were too many tiny edge cases
       that I had to consider, and I wasn't being optimal with it
       since I didn't have enough information on when to do the ordering.

       The real solution is fairly simple, we just iterate through
       the days, if one is going to overflow, we go back in time to 
       the day where it was initialized, and upper_bound the closest
       dry day (which is stored in a set). We then set that to be the
       day we dry it up. The idea is that if, for example, some other
       lake needs that specific dry day EARLIER than the one we just
       set it for, then it would have been encountered first by our
       algorithm anyways. That's pretty much it, easy peasy but I spent
       too long on it. :(
    */
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans;
        set<int> dry;
        const int n = rains.size();
        unordered_map<int,int> m;
        int cache[(int)1e5];
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dry.insert(i);
            }
            cache[i] = 1;
            m[rains[i]] = -1;
        }
        for (int i = 0; i < n; i++) {
            if (rains[i] != 0) {
                if (m[rains[i]] == -1) {
                    m[rains[i]] = i;
                } else {
                    int rem = m[rains[i]];
                    auto it = dry.upper_bound(rem);
                    if (it == dry.end() || *it > i) {
                        return {};
                    }
                    cache[*it] = rains[i];
                    dry.erase(it);
                    m[rains[i]] = i;
                }
            } 
        }
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                ans.push_back(cache[i]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
