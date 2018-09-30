#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10;

vector<int> adj[MAX];
int n, m, deg[MAX];
int C;

int main() {
    scanf("%d", &C);
    while (C--) {
        scanf("%d%d", &n, &m);

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);

            adj[u].push_back(v);
            deg[v]++;
        }

        queue<int> Q;
        bool many = false;
        vector<int> P;
        
        for (int i = 1; i <= n; i++) {
            if (!deg[i]) Q.push(i);            
        }

        while (!Q.empty()) {
            if (Q.size() > 1) many = true;
            
            int u = Q.front();
            P.push_back(u);
            Q.pop();
            
            for (int v : adj[u]) {
                deg[v]--;
                if (!deg[v]) Q.push(v);
            }
        }

        if ((int)P.size() < n) {
            printf("recheck hints\n");
        } else if (many) {
            printf("missing hints\n");
        } else {
            for (int v : P) printf("%d ", v);
            printf("\n");
        }
        
        for (int i = 1; i <= n; i++) {
            deg[i] = 0;
            adj[i].clear();
        }        
    }
}
