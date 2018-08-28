//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;

const int MAX = 2e5 + 10;
//const ll INF = LLONG_MAX;

int n, m;
vector<pll> adj[MAX];
ll a[MAX];
ll dist[MAX];


int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        adj[u].pb(pll(v, w));
        adj[v].pb(pll(u, w));
    }

    set<pll> Q;
    
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        dist[i] = a[i];
        Q.insert(pll(dist[i], i));
    }

    while (!Q.empty()) {
        int u = Q.begin()->second;
        Q.erase(Q.begin());

        debug("Looking to %d\n", u);
        
        for (auto e : adj[u]) {
            int v = e.first;
            ll w = e.second;

            debug("--> [%d] - %lld vs %lld\n", v, dist[u] + 2 * w, dist[v]); 
            
            if ((dist[u] + 2 * w) < dist[v]) {
                if (Q.find(pll(dist[v], v)) != Q.end())
                    Q.erase(pll(dist[v], v));
                dist[v] = dist[u] + 2 * w;
                Q.insert(pll(dist[v], v));
            }
        }

        debug("\n");
    }

    for (int i = 1; i <= n; i++) {
        printf("%lld%c", dist[i], (i == n) ? '\n' : ' ');
    }

    return 0;
}
