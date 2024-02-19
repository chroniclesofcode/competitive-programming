class MKAverage {
public:
    int m, k, rem;
    deque<int> dq;
    multiset<int> left, mid, right;
    int run = 0;
    MKAverage(int _m, int _k) {
        m = _m; k = _k;
        rem = m - 2*k;
    }

    void add(int num) {
        right.insert(num);
    }

    void evict(int num) {
        if (left.find(num) != left.end()) {
            left.erase(left.find(num));
        } else if (mid.find(num) != mid.end()) {
            mid.erase(mid.find(num));
            run -= num;
        } else if (right.find(num) != right.end()) {
            right.erase(right.find(num));
        }
    }

    void balance() {
        while (right.size() > k) {
            run += *right.begin();
            mid.insert(*right.begin());
            right.erase(right.begin());
        }
        while (left.size() < k) {
            run -= *mid.begin();
            left.insert(*mid.begin());
            mid.erase(mid.begin());
        }
        while (*right.begin() < *prev(mid.end())) {
            run += *right.begin();
            run -= *prev(mid.end());
            mid.insert(*right.begin());
            right.erase(right.begin());
            right.insert(*prev(mid.end()));
            mid.erase(prev(mid.end()));
        }
        while (*mid.begin() < *prev(left.end())) {
            run -= *mid.begin();
            run += *prev(left.end());
            left.insert(*mid.begin());
            mid.erase(mid.begin());
            mid.insert(*prev(left.end()));
            left.erase(prev(left.end()));
        }
    }

    void addElement(int num) {
        if (dq.size() < m) {
            add(num);
        } else {
            add(num);
            evict(dq.front());
            dq.pop_front();
        }
        dq.push_back(num);
        if (dq.size() == m) {
            balance();
        }
    }
    
    int calculateMKAverage() {
        if (dq.size() < m) return -1;
        return run / mid.size();

    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
