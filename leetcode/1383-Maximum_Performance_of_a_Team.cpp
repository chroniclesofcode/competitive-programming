class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        #define arr array<int,2>
        #define LL long long
        vector<arr> eng;
        for (int i = 0; i < n; i++) {
            eng.push_back({efficiency[i], speed[i]});
        }
        sort(eng.begin(), eng.end(), greater<arr>());
        priority_queue<int, vector<int>, greater<int>> pq;
        LL tot = 0;
        LL ans = 0;
        for (int i = 0; i < n; i++) {
            int spd = eng[i][1];
            int eff = eng[i][0];
            tot += spd;
            pq.push(spd);
            if (pq.size() > k) {
                tot -= pq.top();
                pq.pop();
            }
            ans = max(ans, tot * eff);
        }
        return ans % ((int)1e9+7);
    }
};
