class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        #define pp pair<int,int>
        #define arr array<int,3>
        vector<pp> r;
        vector<arr> q;
        for (auto room : rooms) {
            r.push_back({room[1], room[0]});
        }
        for (int i = 0; i < queries.size(); i++) {
            auto query = queries[i];
            q.push_back({query[1], query[0], i});
        }
        sort(r.begin(), r.end(), greater<pp>());
        sort(q.begin(), q.end(), greater<arr>());
        int n = r.size();
        int j = 0; // for rooms array
        set<int> s;
        vector<int> answer(queries.size(), 0);
        for (int i = 0; i < q.size(); i++) {
            arr qu = q[i];
            int msz = qu[0]; int pid = qu[1]; int idx = qu[2];
            if (msz > r.begin()->first) {
                answer[idx] = -1;
                continue;
            }
            while (j < n && r[j].first >= msz) {
                s.insert(r[j].second);
                j++; 
            }
            auto it = s.lower_bound(pid);
            int ans = 0, near = INT_MAX;
            if (it != s.end() && near > abs(pid-*it)) {
                near = abs(pid-*it);
                ans = *it;
            }
            if (s.size() > 0 && it != s.begin()) {
                it--;
                if (near >= abs(pid - *it)) {
                    near = abs(pid-*it);
                    ans = *it;
                }
            }
            answer[idx] = ans;
        }
        return answer;
    }
};
