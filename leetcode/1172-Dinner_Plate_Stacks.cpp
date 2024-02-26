class DinnerPlates {
public:
    static constexpr int inf = (int)1e9 + 5;
    int n, cap;
    vector<stack<int>> stacks;
    set<int> empty, some, full;
    DinnerPlates(int capacity) {
        cap = capacity;
        int most = (int)2*1e5 + cap + 1;
        n = most / cap;
        stacks = vector<stack<int>>(n);
        for (int i = 0; i < n; i++) {
            empty.insert(i);
        }
    }
    
    void push(int val) {
        int idx = inf;
        if (!empty.empty()) idx = min(idx, *empty.begin());
        if (!some.empty()) idx = min(idx, *some.begin());
        if (idx == inf) return;
        stacks[idx].push(val);
        if (stacks[idx].size() == 1) {
            empty.erase(idx);
            some.insert(idx);
        }
        if (stacks[idx].size() == cap) {
            some.erase(idx);
            full.insert(idx);
        }
    }
    
    int pop() {
        int idx = -1;
        if (!full.empty()) idx = max(idx, *prev(full.end()));
        if (!some.empty()) idx = max(idx, *prev(some.end()));
        if (idx == -1) return -1;
        int ret = stacks[idx].top();
        stacks[idx].pop();
        if (stacks[idx].size() == cap-1) {
            full.erase(idx);
            some.insert(idx);
        }
        if (stacks[idx].size() == 0) {
            some.erase(idx);
            empty.insert(idx);
        }
        return ret;
    }
    
    int popAtStack(int index) {
        int idx = index;
        if (idx >= n) return -1;
        if (stacks[idx].size() == 0) return -1;
        int ret = stacks[idx].top();
        stacks[idx].pop();
        if (stacks[idx].size() == cap-1) {
            full.erase(idx);
            some.insert(idx);
        }
        if (stacks[idx].size() == 0) {
            some.erase(idx);
            empty.insert(idx);
        }
        return ret;
    }
};
/*
array of stacks. keep track of empty, some, full
stacks. When pushing, you look for the leftmost 
empty vs some stack. When popping, you are looking
for the rightmost full vs some stack.

*/

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
