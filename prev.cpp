class StockPrice {
public:
    multiset<array<int,2>> prices; // price, timestamp
    unordered_map<int, int> tp; // time->price
    int currp = 0, currt = 0;

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (timestamp > currt && tp[timestamp] == 0) {
            prices.insert({ price, timestamp });
            currp = price;
            currt = timestamp;
            tp[currt] = currp;
        } else {
            if (tp[timestamp] != 0)
                prices.erase(prices.find({ tp[timestamp], timestamp }));
            tp[timestamp] = price;
            prices.insert({ price, timestamp });
            if (timestamp == currt) 
                currp = price;
        }
    }
    
    int current() {
        return currp;
    }
    
    int maximum() {
        return (*prev(prices.end()))[0];
    }
    
    int minimum() {
        return (*prices.begin())[0];
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
