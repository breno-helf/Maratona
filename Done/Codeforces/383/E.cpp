//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, a[MAX], b[MAX];
int resp[2 * MAX];
vector<int> adj[2 * MAX];
bool imp = false;

void dfs (int u) {
    for (auto v : adj[u]) {
	if (!resp[v]) {
	    resp[v] = (resp[u] == 1) ? 2 : 1;
	    dfs(v);
	} else if (resp[v] == resp[u]) imp = true;
    }    
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf ("%d%d", a + i, b + i);
	adj[a[i]].pb(b[i]);
	adj[b[i]].pb(a[i]);
    }
    for (int i = 1; i <= 2 * n; i++) {
	if (i % 2) {
	    int p = (i + 1);
	    if (p > 2 * n) p = 1;
	    
	    adj[i].pb(p);
	    adj[p].pb(i);	    
	}
    }
    
    for (int i = 1; i <= 2 * n; i++) {
	if (!resp[i]) {
	    resp[i] = 1;
	    dfs(i);
	}
    }
    if (imp) puts("-1");
    else {
	for (int i = 1; i <= n; i++) {
	    printf("%d %d\n", resp[a[i]], resp[b[i]]);
	}
    }
    return 0;
}
