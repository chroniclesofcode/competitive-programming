class MovieRentingSystem {
public:
    #define arr2 array<int,2>
    #define arr3 array<int,3>
    unordered_map<int, set<arr2>> movies;
    unordered_map<int, unordered_map<int,int>> shopmov;
    set<arr3> rented;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        int s, m, p;
        for (int i = 0; i < entries.size(); i++) {
            s = entries[i][0]; m = entries[i][1]; p = entries[i][2];
            shopmov[s][m] = p;
            movies[m].insert({ p, s });
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        int ct = 0;
        for (auto it = movies[movie].begin(); it != movies[movie].end(); it++) {
            if (ct == 5) break;
            ans.push_back((*it)[1]);
            ct++;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int p = shopmov[shop][movie];
        movies[movie].erase({p,shop});
        rented.insert({p, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int p = shopmov[shop][movie];
        rented.erase({p, shop, movie});
        movies[movie].insert({p, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int ct = 0;
        for (auto it = rented.begin(); it != rented.end(); it++) {
            if (ct == 5) break;
            ans.push_back({(*it)[1], (*it)[2]});
            ct++;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
