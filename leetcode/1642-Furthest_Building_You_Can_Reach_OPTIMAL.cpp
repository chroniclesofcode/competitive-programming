class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 1;
        for (; i < h.size(); i++) {
            if (h[i] <= h[i-1]) {
                continue;
            }
            pq.push(h[i]-h[i-1]);
            if (pq.size() > ladders) {
                int min_v = pq.top();
                pq.pop();
                bricks -= min_v;
                if (bricks < 0) return i-1;
            }
        }
        return h.size() - 1;
    }
};
