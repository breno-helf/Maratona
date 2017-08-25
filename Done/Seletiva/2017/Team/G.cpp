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
int resp, mrk[MAX];
int p[MAX];
int h[MAX];

void bfs(int u) {
    mrk[u] = 1;
    queue<int> Q;
    Q.push(u);
    p[u] = u;
    while(!Q.empty()) {
	u = Q.front();
	Q.pop();
	vector<int> guys;
	guys.pb(u);
	for (int v : adj[u]) {
	    if (!mrk[v]) {
		h[v] = h[u] + 1;
		mrk[v] = 1;
		p[v] = u;
		Q.push(v);
	    }

	    if (h[v] == h[u]) guys.pb(v);
	}
	int d = p[guys[0]];
	bool ok = true;
	for (int v : guys) {
	    if (p[v] != d) ok = false;
	}
	if (ok) guys.pb(d);
	resp = max(resp, (int)guys.size());
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
	int u, v;
	scanf("%d%d", &u, &v);
	adj[u].pb(v);
	adj[v].pb(u);
    }
    resp = 1;
    bfs(1);
    
    printf("%d\n", resp);
}
