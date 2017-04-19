//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct node {
    int v, d;
    node (int V = 0, int D = -1): v(V), d(D) {}
    bool operator < (const node p) const {
	return (p.v < v || (p.v == v && p.d < d));
    }
    bool operator == (const node p) const {
	return ((v == p.v) && (d == p.d));
    }
};

int n, g, cnt;
int mrk[MAX];
map<int, node> Vx;
map<node, int> ID;
vector<int> adj[MAX];
map<pii, int> DIR;

void lig (int i, int a, int dir) {
    if (DIR.find(pii(i, a)) != DIR.end()) {
	int u = ID[node(a, DIR[pii(i, a)])];
	int v = ID[node(i, dir)];
	debug ("(%d, %d) eh adj a (%d, %d)\n", i, dir, a, DIR[pii(i, a)]);
	adj[u].pb(v);
	adj[v].pb(u);
    } else {
	DIR[pii(a, i)] = dir; 
    }
}

int dfs (int u) {
    int ret = 0;
    if (Vx[u].v == g) ret = 1;
    mrk[u] = 1;
    for (int v : adj[u]) {
	if (!mrk[v])
	    ret |= dfs(v);	
    }
    return ret;
}

    
int main () {
    int t;
    for (scanf ("%d", &t); t; t--) {
	memset(mrk, 0, sizeof(mrk));
	ID.clear();
	Vx.clear();
	DIR.clear();
	for (int i = 0; i < MAX; i++) {
	    adj[i].clear();
	}
	cnt = 0;
	scanf ("%d%d", &n, &g);
	for (int i = 1; i <= n; i++) {
	    int a, b, c, d;
	    scanf ("%d%d%d%d", &a, &b, &c, &d);
	    if (ID.find(node(i, 0)) == ID.end()) {
		ID[node(i, 0)] = ++cnt;
		Vx[cnt] = node(i, 0);
	    }
	    
	    if (ID.find(node(i, 1)) == ID.end()) {
		ID[node(i, 1)] = ++cnt;
		Vx[cnt] = node(i, 1);
	    }

	    lig (i, a, 0);
	    lig (i, c, 0);
	    lig (i, b, 1);
	    lig (i, d, 1);
	}
	debug ("--> %d\n", cnt);
	
	int resp = 0;
	for (int i = 1; i <= cnt; i++) {
	    if (!mrk[i]) {
		if (!dfs(i)) resp++;
	    }	    
	}
	printf("%d\n", resp);
    }
    
}
