class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        using arr2 = array<int,2>;
        vector<arr2> diffs;
        int n = profits.size();
        k = min(k, n);
        for (int i = 0; i < n; i++) {
            diffs.push_back({capital[i], profits[i]});
        }
        sort(diffs.begin(), diffs.end());
        priority_queue<int> pq;
        int tot = 0;
        int curr = w;
        for (int i = 0; i < n; i++) {
            auto& [cap, prof] = diffs[i];
            if (cap <= curr) {
                pq.push(prof);
                continue;
            }
            while (!pq.empty() && curr < cap && tot < k) {
                curr += pq.top();
                tot++;
                pq.pop();
            }
            if (curr < cap) {
                break;
            } else {
                pq.push(prof);
            }
        }
        while (!pq.empty() && tot < k) {
            curr += pq.top();
            tot++;
            pq.pop();
        }
        return curr;
    }
};
