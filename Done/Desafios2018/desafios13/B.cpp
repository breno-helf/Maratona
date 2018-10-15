#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 2e3 + 10;

int n, c, x, y;
vector<pii> adj[MAX];
int key[MAX];
int f[MAX];

void dfs(int u, int s, vector<int>& ans) {
    for (pii e : adj[u]) {
        int v = e.first;
        int k = e.second;

        if (v == s) {
            ans.push_back(e);
            return;
        } else if (v != p) {
            dfs(v, u, s, ans);
            if (!ans.empty()) {
                ans.push_back(e);
                return;
            }
        }
    }
}

vector<int> getPath(int a, int b) {
    vector<int> ret;
    dfs(a, b, ret);
    reverse(ret.begin(), ret.end());
    return ret;    
}

vector<int> getValidPath(int a, int b, map<int, int> K) {
    vector<pii> cur = getPath(a, b);
    vector<int> ret;   
    if (cur.empty()) return ret;
    
    for (pii e : ret) {
        int u = e.first;
        int k = e.second;
        
        if (k == -1 || K[k] == 1) {
            ret.push_back(u);
        } else {
            vector<int> A = getValidPath(u, key[k], K);
            if (A.empty()) return A;

            for (int i = 1; i < A.size(); i++) {
                ret.push_back(A[i]);
            }

            reverse(A.begin(), A.end());
            
            for (int i = 1; i < A.size(); i++) {
                ret.push_back(A[i]);
            }
        }
    }

    return ret;
}

int main() {
    
    while (scanf("%d %d %d %d", &n, &c, &x, &y) != 0) {
        if (n == 0 && c == 0 && x == 0 && y == 0) break;
                
        for (int i = 0; i < n; i++) {
            scanf("%d", key + i);
        }

        for (int i = 1; i < n; i++) {
            int u, v, l;
            scanf("%d %d %d", &u, &v, &l);
            adj[u].push_back(pii(v, l));
            adj[v].push_back(pii(u, l));
        }

        vector<int> ans = getValidPath(x, y, map<int, int>());

        if (ans.empty()) {
            puts("Impossible");
            continue;            
        }
        
        printf("%d:", (int)ans.size());
        for (int v : ans) {
            printf(" %d");
        }
        printf("\n");

        for (int i = 0; i < n; i++) {
            adj[i].clear();
            f[i] = 0;
        }
    }
    
    return 0;
}
