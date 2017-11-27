//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int MAXP = 22;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct edge {
    int u, v;
    ll w;
    edge(int U = 0, int V = 0, ll W = 0):
	u(U), v(V), w(W) {}

    bool operator < (const edge ot) const {
	return w < ot.w;
    }
};

int n, m;
vector<pii> adj[MAX];
vector<edge> E, ans;
int sz[MAX], P[MAX];
pii pre[MAX][MAXP], pai[MAX];
int h[MAX];

void dfs(int x, int u) {
    for(auto& v : adj[x]) {
	int nxt = v.first;
	ll e = v.second;
	if(nxt != u) {
	    h[nxt] = h[x] + 1;
	    pai[nxt] = mp(x,e);
	    dfs(nxt, x);
	}
    }
}

int find(int a) {
    if (a == P[a]) return a;
    else return (P[a] = find(P[a]));
}

int une(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return 0;

    if (sz[a] < sz[b]) swap(a, b);

    P[b] = a;
    sz[a] += sz[b];
    
    return 1;
}

void precalc() {
    for(int i = 1; i <= n; i++) pre[i][0] = pai[i];

    for(int k = 1; k < MAXP; k++) {
	for(int i = 1; i <= n; i++) {
	    pre[i][k] = mp(pre[ pre[i][k-1].first ][k-1].first, max(pre[i][k-1].second, pre[ pre[i][k-1].first ][k-1].second));
	}
    }
}


ll max_edge(int x, int y) {
    ll ret = 0;
    if(h[x] > h[y]) swap(x, y);
    int dif = h[y] - h[x];
  
    for (int i = MAXP - 1; i >= 0; i--) {
	if ((1<<i) <= dif) {
	    ret = max(ret, pre[y][i].second);
	    y = pre[y][i].first;
	    dif -= (1<<i);
	}
    }

    if (x == y) return ret;

    for (int i = MAXP - 1; i >= 0; i--) {
	if (pre[x][i].first != pre[y][i].first) {
	    ret = max(ret, max(pre[x][i].second, pre[y][i].second));
	    x = pre[x][i].first;
	    y = pre[y][i].first;
	}
    }

    ret = max(ret, max(pre[x][0].second, pre[y][0].second));

    return ret;
}

ll kruskal() {
    ll ret = 0;
    for (auto e : E) {
	int u = e.u;
	int v = e.v;
	ll w = e.w;
	//printf("%d %d\n", find(u), find(v));
	if (find(u) != find(v)) {
	    //debug("--> %d %d %d\n", u, v, w);
	    une(u, v);
	    adj[u].pb(mp(v, w));
	    adj[v].pb(mp(u, w));
	    ret += w;
	}
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
	P[i] = i; sz[i] = 1;
    }
    

    ll tot = 0;
    for (int i = 0; i < m; i++) {
	int u, v;
	ll w;
	scanf("%d%d%lld", &u, &v, &w);
	ans.pb(edge(u, v, w));
	E.pb(edge(u, v, w));
    }

    sort(E.begin(), E.end());
    tot = kruskal();
    E.clear();
    
    pai[1] = mp(1, 0);
    dfs(1, 1);

    precalc();

    //debug("--> %lld\n", tot);
    
    for (int i = 0; i < m; i++) {
	edge e = ans[i];
	int u = e.u;
	int v = e.v;
	ll w = e.w;

	printf("%lld\n", tot + w - (ll)(max_edge(u, v)));
    }
    
}
