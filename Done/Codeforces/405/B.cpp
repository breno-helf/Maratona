//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
vector<int> adj[MAX];
ll deg[MAX];
ll cmp[MAX], sz[MAX], cnt;

void dfs (int u, int id) {
    cmp[u] = id;
    sz[id]++;
    for (auto v : adj[u]) {
	if (!cmp[v]) dfs(v, id);
    }
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
	int a, b;
	scanf("%d%d", &a, &b);
	deg[a]++;
	deg[b]++;
	adj[a].pb(b);
	adj[b].pb(a);
    }
    cnt = 1;
    for (int i = 1; i <= n; i++) {
	if (!cmp[i]) dfs(i, cnt++);
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
	if (deg[i] != (sz[cmp[i]] - 1)) {
	    //debug("%d -- %lld %lld\n", i, sz[cmp[i]] -1, deg[i]);
	    ok = false;
	}
    }
    printf("%s\n", ok ? "YES" : "NO");
    return 0;
}
