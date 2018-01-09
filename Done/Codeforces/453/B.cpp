//If you are trying to hack me I wish you can get it, Good Luck :D.
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

int n, p[MAX];
int c[MAX];
vector<int> adj[MAX];
int sub[MAX];
int mrk[MAX];

void dfs(int u, int d) {
    sub[u] = 1;
    for (int v : adj[u]) {
	if (v != d) {
	    dfs(v, u);
	    sub[u] += sub[v];
	}
    }
}

int main() {
    scanf("%d", &n);
    p[1] = 1;
    for (int i = 2; i <= n; i++) {
	scanf("%d", p + i);
	adj[i].pb(p[i]);
	adj[p[i]].pb(i);
    }

    for (int i = 1; i <= n; i++) {
	scanf("%d", c + i);
    }

    dfs(1, 1);
    queue<int> Q;

    for (int i = 1; i <= n; i++) {
	if (sub[i] == 1) {
	    Q.push(i);
	    debug("--> %d\n", i);
	    mrk[i] = 1;
	}
    }

    int resp = 0;
    
    while (!Q.empty()) {
	int u = Q.front();
	Q.pop();

	if (c[u] != c[p[u]]) {
	    resp++;
	    debug("==> %d\n", u);
	}
	
	if (u != 1 && !mrk[p[u]]) {
	    Q.push(p[u]);
	    mrk[p[u]]++;
	}
    }

    printf("%d\n", resp + 1);
}

