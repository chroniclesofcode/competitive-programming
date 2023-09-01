class Solution {
public:
    void debug(set<array<int,2>, greater<array<int,2>>> s) {
        cout << "\nS: ";
        for (auto it = s.begin(); it != s.end(); it++) {
            cout << (*it)[0] << ' ' << (char)((*it)[1]+'a') << " | ";
        }
        cout << endl;
    }
    int leastInterval(vector<char>& tasks, int n) {
        #define arr array<int,2>
        set<arr, greater<arr>> s;
        unordered_map<int, int> m;
        unordered_map<int, int> freq;
        for (int i = 0; i < tasks.size(); i++) {
            int c = tasks[i] - 'a';
            freq[c]++;
        }
        for (auto it = freq.begin(); it != freq.end(); it++) {
            s.insert({it->second, it->first});
            m[it->first] = -1;
        }
        int i = 0;
        int num, c;
        for (; i < 1e6; i++) {
            bool fin = true;
            for (auto it = s.begin(); it != s.end(); it++) {
                num = (*it)[0];
                c = (*it)[1];
                if (num != 0) fin = false;
                if (num > 0 && (m[c] == -1 || i - m[c] > n)) {
                    num--;
                    m[c] = i;
                    s.erase(it);
                    s.insert({num,c});
                    break;
                }
            }
            if (fin) break;
        }
        
        return i;
    }
};
