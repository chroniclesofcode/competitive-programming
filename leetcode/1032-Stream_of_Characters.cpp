class StreamChecker {
public:
    /*
       Fairly simple question to do with hashing. Just hash
       all the suffixes, and keep comparing to hash in O(1) time
       using a hashmap. 

       You can also do it with a trie, for every suffix added you just
       keep trying to progress down the trie until you hit an end.
       Not really recommended though.
    */
    unordered_map<long long, long long> suf, finale;
    string cur = "";
    StreamChecker(vector<string>& words) {
        for (auto str : words) {
            int p = 31, m = 1e9+9; 
            long long hash = 0, pp = 1;
            for (int i = str.size()-1; i >= 0; i--) {
                hash = (hash + (str[i]  - 'a' + 1) * pp) % m;
                suf[hash] = 1;
                pp = (pp * p) % m;
            }
            finale[hash] = 1;
        }
    }
    
    bool query(char letter) {
        cur += letter;
        int p = 31, m = 1e9 + 9;
        long long hash = 0, pp = 1;
        for (int i = cur.size() - 1; i >= 0; i--) {
            hash = (hash + (cur[i]-'a'+1) * pp) % m;
            pp = (pp * p) % m;
            if (!suf[hash]) {
                return false;
            } else if (finale[hash]) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
