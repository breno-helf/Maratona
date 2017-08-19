//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 51234;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
vector<int> adj[MAX];
int k;
int f[MAX];

void dfs(int u, int c) {
    f[u] = c % k + 1;
    for (int v : adj[u]) {
	if (!f[v]) {
	    dfs(v, c + 1);
	}
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
	int u, v;
	scanf("%d%d", &u, &v);
	adj[u].pb(v);
	adj[v].pb(u);
    }

    if (k == 1 && m != 0) {
	printf("-1\n");
	return 0;
    }

    for (int i = 1; i <= n; i++) {
	if (!f[i]) dfs(i, 1);
	printf("%d\n", f[i]);
    }
}


