class StockSpanner {
public:
    StockSpanner() {
        count = 0;
    }
    
    int next(int price) {
        if (s.empty()) {
            s.push({ price, count });
            count++;
            return 1;
        }
        int ans = 1;
        while (!s.empty()) {
            array<int,2> val = s.top();
            if (val[0] > price) {
                ans = count - val[1];
                break;
            } else {
                s.pop();
            }
        }
        if (s.empty()) {
            ans = count + 1;
        }
        s.push({ price, count });
        count++;
        return ans;
    }
    int count;
    stack<array<int,2>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
