//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 11234;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m, k, t;
int deg[MAX];
int rel[MAX];
vector<int> adj[MAX];
set<pii> Q;

void dfs (int u) {
    debug("-- %d %d\n", u, rel[u]);
    Q.erase(pii(rel[u], u));
    int nxt = 0;
    
    for (auto v : adj[u]) {
	debug(" %d -- %d ||", v, rel[v]);
	if (rel[v] == (rel[u] - 1))
	    nxt = v;
    }
    debug(" saw\n");
    if (nxt) dfs(nxt);
}

int main () {
    for (scanf ("%d", &t); t; t--) {	
	memset(deg, 0, sizeof(deg));
	memset(rel, 0, sizeof(rel));
	Q.clear();
	for (int i = 0; i < MAX; i++) {
	    adj[i].clear();
	}
	queue<int> fol;

	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
	    int a, b;
	    scanf ("%d%d", &a, &b);
	    deg[a]++; deg[b]++;
	    adj[a].pb(b);
	    adj[b].pb(a);
	}

	for (int i = 1; i <= n; i++) {
	    if (deg[i] == 1) {
		fol.push(i);
		rel[i] = 1;
	    }
	    debug("%2d ", rel[i]);
	}
	while (!fol.empty()) {
	    int u = fol.front();
	    debug("processando %d -- %d\n", u, rel[u]);
	    for (auto v : adj[u]) {
		deg[v]--;
		debug("    Olhando %d -- %d %d\n", v, deg[v], rel[v]);
		if (deg[v] == 1 && !rel[v]) {
		    fol.push(v);
		    rel[v] = rel[u] + 1;
		}
	    }
	    fol.pop();
	}

	int resp = n;
	debug("\n");
	for (int i = 1; i <= n; i++) debug("%2d ", i);
	debug("\n");
	for (int i = 1; i <= n; i++) {
	    if (rel[i]) Q.insert(pii(rel[i], i));
	    else resp--;
	    debug ("%2d ", rel[i]);
	    
	}
	debug("\n");
	while (!Q.empty() && k) {
	    int u = prev(Q.end())->second;
	    debug(">>>> saving %d\n", u);
	    dfs(u); k--;
	    debug("\n");
	    resp -= rel[u]; 
	}
	debug("=== ");
	printf("%d\n", resp);
	debug("\n");
    }
    return 0;
}
