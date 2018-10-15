#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

int n, m, x, s;
vector<int> adj[MAX];

int mrk[MAX];
int out[MAX];

int main() {
    scanf("%d%d%d%d", &n, &m, &x, &s);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> Q;
    Q.push(s);

    mrk[s] = 1;
    
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            out[v]++;
            if (adj[v].size() <= 2 * out[v]) {
                if (!mrk[v]) {
                    Q.push(v);
                    mrk[v] = 1;
                }
            }
        }
    }

    if (mrk[x]) puts("leave");
    else puts("stay");

    return 0;
}
