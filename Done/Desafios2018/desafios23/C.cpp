#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX = 1e5 + 10;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

struct edge {
    int v;
    ll c, w;

    edge(int V, ll C, ll W):
        v(V), c(C), w(W) {}

    bool operator < (const edge ot) const {
        return w < ot.w;
    }
};

int T;
int n, m;
ll k;
vector<edge> adj[MAX];
ll dist[MAX];

ll cost(ll wisdom) {    
    memset(dist, (int)LINF, sizeof(dist));

    set<pll> Q;
    dist[1] = 0;
    Q.insert(pll(0, 1));
    
    while (!Q.empty()) {
        int u = Q.begin()->second;
        Q.erase(Q.begin());

        for (edge e : adj[u]) {
            int v = e.v;
            ll w = e.w, c = e.c;
            if (w > wisdom) continue;
            
            if (dist[v] > dist[u] + c) {
                if (dist[v] != LINF) Q.erase(pll(dist[v], v));

                dist[v] = dist[u] + c;
                Q.insert(pll(dist[v], v));
            }
        }
    }

    //printf("Wisdom = %lld -- Custo[%d] = %lld\n", wisdom, n, dist[n]); 
    
    return dist[n];
}

int main() {
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d %lld", &n, &m, &k);

        for (int i = 0; i < m; i++) {
            int u, v;
            ll c, w;
            scanf("%d %d %lld %lld", &u, &v, &c, &w);
            adj[u].push_back(edge(v, c, w));
            adj[v].push_back(edge(u, c, w));
        }

        ll l = 0, r = 1e9 + 10;

        while (l < r) {
            ll mid = (l + r) / 2;

            if (cost(mid) < k) r = mid;
            else l = mid + 1;
        }

        if (cost(l) < k) printf("%lld\n", l);
        else printf("-1\n");
        
        for (int i = 0; i <= n; i++) adj[i].clear();
    }

    return 0;
}
