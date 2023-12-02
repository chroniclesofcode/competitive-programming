class Solution {
public:
    int BIT[3*(int)1e4+1];
    int n;
    void add(int x) {
        for (; x <= n; x += x&-x) {
            BIT[x]++;
        }
    }

    int query(int x) {
        int sum = 0;
        for (; x > 0; x -= x&-x) {
            sum += BIT[x];
        }
        return sum;
    }
    string minInteger(string num, int k) {
        queue<int> q[10];
        n = num.size();
        for (int i = 0; i < n; i++) {
            int ch = num[i] - '0';
            q[ch].push(i);
        }
        string ret(n, 'z');
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++) {
            if (k == 0) break;
            for (int c = 0; c < 10; c++) {
                int cost = q[c].front() - query(q[c].front()+1);
                if (!q[c].empty() && cost <= k) {
                    ret[i] = c + '0';
                    mark[q[c].front()] = 1;
                    add(q[c].front()+1);
                    k -= cost;
                    q[c].pop();
                    break;
                }
            }
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (mark[i]) continue;
            while (j < n && ret[j] != 'z') j++;
            ret[j] = num[i];
        }
        return ret;
    }
};
