class Solution {
public:
    #define LL long long
    LL ct[120];
    int mostBooked(int n, vector<vector<int>>& meetings) {
        #define arr array<LL,2>
        multiset<arr> s;
        multiset<LL> fr;
        for (LL i = 0; i < n; i++) {
            fr.insert(i);
        }

        sort(meetings.begin(), meetings.end());
        for (LL i = 0; i < meetings.size(); i++) {
            LL st = meetings[i][0];
            LL ed = meetings[i][1];
            while (s.size() && (*s.begin())[0] <= st) {
                fr.insert((*s.begin())[1]);
                s.erase(s.begin());
            }
            if (fr.size()) {
                auto it = fr.begin();
                s.insert({ ed, *it });
                ct[*it]++;
                fr.erase(it);
            } else {
                LL tmped = (*s.begin())[0];
                fr.insert((*s.begin())[1]);
                s.erase(s.begin());
                auto it = fr.begin();
                s.insert({ tmped + (ed-st), *it });
                ct[*it]++;
                fr.erase(it);
            }
        }
        LL ans = 0;
        for (LL i = 0; i < n; i++) {
            if (ct[ans] < ct[i]) {
                ans = i;
            }
        }
        return ans;
    }
};
