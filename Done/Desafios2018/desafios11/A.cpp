#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

vector<int> adj[MAX];
int h[MAX];

void dfs(int u, int p) {
    h[u] = h[p] + 1;

    for (int v : adj[u]) {
        if (h[v] == -1) dfs(v, u);
    }
}

int main() {
    int c, n;
    scanf("%d", &c);
    
    while (c--) {
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }


        memset(h, -1, sizeof(h));
        dfs(0, 0);
        int u = 0;
        for (int v = 0; v < n; v++) {
            //printf("(%d) - %d\n", v, h[v]);
            if (h[v] > h[u]) u = v;
        }
        //printf("==> %d\n", u);
        
        memset(h, -1, sizeof(h));
        dfs(u, u);

        for (int v = 0; v < n; v++) {
            if (h[v] > h[u]) u = v;
            adj[v].clear();
        }

        printf("%d\n", (h[u] + 1)/2);
    }


    return 0;
}
