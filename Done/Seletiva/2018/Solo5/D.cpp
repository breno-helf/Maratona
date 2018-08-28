//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 20;
const int TEST = 104000;

vector<int> adj[MAX];
int n, m;
int color[MAX];

bool dfs2(int u, int c) {
    color[u] = (c == 1 ? 2 : 1);
    for (int v : adj[u]) {
        if (color[v] == 0) dfs2(v, color[u]);
        else if (color[v] == color[u]) return false;
    }
    return true;
}


bool bipartite() {
    memset(color, 0, sizeof(color));
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            if (!dfs2(i, 1)) return false;
        }
    }
    return true;
}

bool paint(int num) {
    vector<int> index;
    for (int i = 0; i < n; i++) index.pb(i);
    
    for (int i = 0; i < TEST; i++) {
        random_shuffle(index.begin(), index.end());
        memset(color, 0, sizeof(color));
        bool ok = true;
        for (int k = 0; k < n; k++) {
            int u = index[k];
            int used[5] = {0, 0, 0, 0, 0};
            for (int v : adj[u]) {
                used[color[v]] = 1;
            }
            for (int c = 1; c <= num; c++) {
                if (used[c] == 0) {
                    color[u] = c;
                    break;
                }
            }
            
            if (color[u] == 0) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

bool tripartite() {
    return paint(3);
}

bool planar() {
    return paint(4);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }

        if (m == 0) {
            puts("1");
        } else if (bipartite()) {
            puts("2");
        } else if (tripartite()) {
            puts("3");
        } else if (planar()) {
            puts("4");
        } else {
            puts("many");
        }
        for (int i = 0; i < n; i++) adj[i].clear();
    }

    return 0;
}
