class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        using arr2 = array<int,2>;
        vector<arr2> diffs;
        int n = profits.size();
        k = min(k, n);
        for (int i = 0; i < n; i++) {
            diffs.push_back({profits[i], capital[i]});
        }
        sort(diffs.begin(), diffs.end(), greater<arr2>());
        priority_queue<arr2, vector<arr2>, greater<arr2>> pq;
        int curr = w;
        int tot = 0;

        auto process_pq = [&]() {
            vector<arr2> tmp;
            while (!pq.empty() && pq.top()[0] <= curr) {
                auto tp = pq.top();
                tmp.push_back({tp[1], tp[0]});
                pq.pop();
            }
            sort(tmp.begin(), tmp.end(), greater<arr2>());
            int add = min((int)tmp.size(), k - tot);
            for (int j = 0; j < add; j++) {
                curr += tmp[j][0];
            }
            tot += add;
        };
        
        for (int i = 0; i < n; i++) {
            if (diffs[i][0] < 0) break;
            if (curr < diffs[i][1]) {
                pq.push({diffs[i][1], diffs[i][0]});
                continue;
            }
            curr += diffs[i][0];
            tot++;
            process_pq();
            if (tot == k) break;
        }
        process_pq();
        return curr;
    }
};
