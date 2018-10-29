#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX = 1e4 + 10;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m;
double x;

vector<pll> adj[MAX];
ll dist[MAX];

ll shortest_path(int M) {
    memset(dist, (int)LINF, sizeof(dist));
    
    set<pll> Q;

    dist[1] = 0;
    Q.insert(pll(0, 1));

    while (!Q.empty()) {
        int u = Q.begin()->second;
        Q.erase(Q.begin());

        for (auto e : adj[u]) {
            int v = e.first;
            ll w = e.second;

            if (w > M) continue;
            
            if (dist[u] + w < dist[v]) {
                if (dist[v] != LINF) Q.erase(pll(dist[v], v));
                dist[v] = dist[u] + w;
                Q.insert(pll(dist[v], v));
            }
        }
    }

    return dist[n];
}

bool ok(int M, ll lim) {
    bool test = (shortest_path(M) <= lim);

    //debug("Testing %d -- %s\n", M, test ? "OK" : "FAIL");
    
    return test;
}

int main() {
    scanf("%d %d %lf", &n, &m, &x);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;

        scanf("%d %d %lld", &u, &v, &w);

        adj[u].push_back(pll(v, w));
        adj[v].push_back(pll(u, w));        
    }

    ll S = shortest_path(1e9 + 1);

    ll lim = ((double) S) * ((x + 100.0) / 100.0);

    //debug("--> %lld %lld\n", S, lim);
    
    int l = 1, r = 1e9 + 1;
    
    while (l < r) {
        int mid = (l + r) / 2;

        if (ok(mid, lim)) r = mid;
        else l = mid + 1;
    }

    printf("%d\n", l);

    return 0;
}
