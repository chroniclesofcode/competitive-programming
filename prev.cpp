#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

const int MX = 500100;

struct trieNode {
    int sz, link, cnt;
    map<char,int> nextm;
} node[2*MX];

char curr_string[MX], target_string[5*MX];
int N, M, queries, sz, last;

void connect_node(char c){
    int cur = sz++;
    node[cur].sz = node[last].sz + 1;
    node[cur].cnt = 1;
    int p = last;
    while(p != -1 && !node[p].nextm.count(c)) {
        node[p].nextm[c] = cur;
        p = node[p].link;
    }
    if(p == -1) {
        node[cur].link = 0;
    } else {
        int q = node[p].nextm[c];
        if(node[p].sz + 1 == node[q].sz) {
            node[cur].link = q;
        } else {
            int clone = sz++;
            node[clone].sz = node[p].sz + 1;
            node[clone].nextm = node[q].nextm;
            node[clone].link = node[q].link;
            while(p != -1 && node[p].nextm[c] == q) {
                node[p].nextm[c] = clone;
                p = node[p].link;
            }
            node[q].link = node[cur].link = clone;
        }
    }
    last = cur;
}



void upd(){
    vector<int> states_by_sz[sz];
    for(int i = 0; i < sz; i++) {
        states_by_sz[node[i].sz].push_back(i);
    }
    for(int i = sz-1; i >= 0; i--) {
        for (int u : states_by_sz[i]) {
            if(node[u].link != -1) {
                node[node[u].link].cnt += node[u].cnt;
            }
        }
    }
}

void build() {
    node[0].sz = 0;
    node[0].link = -1;
    sz = 1;
    last = 0;
}

int qry() {
    int u = 0;
    for(int i = 0; i < M; i++){
        char c = target_string[i];
        if(!node[u].nextm.count(c))
            return 0;
        else                        
            u = node[u].nextm[c];
    }
    return node[u].cnt;
}

int main(){
    scanf(" %s %d", curr_string, &queries);

    N = (int)strlen(curr_string);

    build();
    for (int i = 0; i < N; i++) {
        connect_node(curr_string[i]);
    }
    upd();

    for (int i =  0; i < queries; i++) {
        scanf(" %s", target_string);
        M = (int)strlen(target_string);
        printf("%d\n", qry());
    }
}

/*
   Try this if you are stuck:
1) binary search on answer
2) Try solving it in reverse
3) Think of a simpler problem 
4) Think of elements which are special
   (like minimum, maximum, deepest node in tree, root)
5) Is it graph problem?
    - super node? dp? cycles?
6) sorting on something e.g. queries?
7) Parity? something special
8) is it monotonic? could you use a PQ/stack/queue?

   EDGE CASES! N = 1, 2...
   LONG LONG
*/
