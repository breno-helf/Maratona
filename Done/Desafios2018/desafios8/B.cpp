#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 112;
const int INF = 0x3f3f3f3f;

vector<pii> T, S;
int invalid[MAX], n;
int adj[MAX][MAX];
int mrk[MAX];
int par[MAX];

int dist(pii A, pii B) {
    return (abs(A.first - B.first) + abs(A.second - B.second));
}

bool dfs(int u, int D) {
    for (int v = 0; v < n; v++) {
        if (adj[u][v] <= D && !mrk[v]) {
            mrk[v] = 1;
            if (par[v] < 0 || dfs(par[v], D)) {
                par[v] = u;
                return true;
            }
        }
    }

    return false;
}

bool test(int D) {
    memset(par, -1, sizeof(par));

    for (int u = 0; u < n; u++) {
        memset(mrk, 0, sizeof(mrk));
        if (dfs(u, D) == false) return false;        
    }

    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        S.push_back(pii(x, y));
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        T.push_back(pii(x, y));
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = dist(S[i], T[j]);
        }
    }
    // Busca Binaria + Bipartite Matching
    int l = 0, r = INF;
    while (l < r) {
        int mid = (l + r) / 2;
        if (test(mid))
            r = mid;
        else
            l = mid + 1;
    }
    
    printf("%d\n", l);
}
