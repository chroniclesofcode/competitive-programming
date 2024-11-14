class Encrypter {
public:
    vector<char> kys;
    vector<string> vals;
    vector<string> dic;
    unordered_map<string, int> ct;
    int mp[26];
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        memset(mp, -1, sizeof(mp));
        for (int i = 0; i < keys.size(); i++) {
            mp[keys[i] - 'a'] = i; // corresponds to values[i]
        }
        kys = keys;
        vals = values;
        dic = dictionary;
        for (auto &s : dictionary) {
            string done = encrypt(s);
            if (done == "") continue;
            ct[done]++;
        }
    }
    
    string encrypt(string word1) {
        string ans;
        for (char c : word1) {
            if (mp[c-'a'] == -1) return "";
            ans += vals[mp[c-'a']];
        }
        return ans;
    }
    
    int decrypt(string word2) {
        return ct[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
