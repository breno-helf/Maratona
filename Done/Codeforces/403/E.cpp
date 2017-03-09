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

int n, m, k, mark[MAX];
vector<int> adj[MAX];
vector<int> path;
void dfs (int u) {
    mark[u] = 1;
    path.pb(u);
    for (int v : adj[u]) {
	if (!mark[v]) {
	    dfs(v);
	    path.pb(u);
	}
    }
}

int main () {
    scanf("%d%d%d", &n, &m, &k);
    
    for (int i = 0; i < m; i++) {
	int x, y;
	scanf("%d%d", &x, &y);
	adj[x].pb(y);
	adj[y].pb(x);
    }
    
    int walk = (2 * n + k - 1) / k;
    dfs(1);
    int sz = path.size();
    
    for (int i = 0; i < sz; i += walk) {
	int num = (i + walk < sz) ? (walk) : (sz - i);
	printf ("%d ", num);
	for (int j = 0; j < num; j++) {
	    printf("%d ", path[i + j]);
	}
	printf("\n");
    }
    for (int i = ((sz + walk - 1)/walk); i < k; i++)
	printf("1 1\n");
    return 0;
}

