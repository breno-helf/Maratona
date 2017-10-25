//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 5123;
const ll  INF = 1e17;
const ll  MOD = 1000000007;

int n, m;
vector<pii> adj[MAX];
vector<int> S;
set<int> M;

ll mrk[2][MAX];
   
void bfs(int T) {
    queue<pii> Q;
    for (int k = 0; k < 2; k++) {
	for (int v = 1; v <= n; v++) {
	    if (mrk[k][v] != INF && (T % 2 == mrk[k][v] % 2)) {
		Q.push(pii(k, v));
	    }
	}
    }
    
    //debug("\nChamada\n");
    while (!Q.empty()) {
	pii p = Q.front();
	int t = p.first, u = p.second;
	//assert(mrk[t][u] % 2 == t);
	Q.pop();
	//debug("--> %d %d (%lld)\n", t, u, mrk[t][u]);
	for (auto e : adj[u]) {
	    int w = e.first, v = e.second;
	    
	    if (w > T) break;

	    ll cur = mrk[t][u];

	    if (cur % 2 == T % 2) cur = max(cur, (ll)T);
	    else cur = max(cur, (ll)T + 1LL);
	    
	    if ((cur + 1LL) < mrk[t ^ 1][v]) {
		Q.push(pii(t ^ 1, v));
		mrk[t ^ 1][v] = cur + 1LL;
	    }
	}	
    }
}


int main() {
    for (int k = 0; k < 2; k++) {
	for (int i = 0; i < MAX; i++) mrk[k][i] = INF;
    }
    mrk[0][1] = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
	int u, v, w;
	scanf("%d %d %d", &u, &v, &w);
	adj[u].pb(pii(w, v));
	adj[v].pb(pii(w, u));
	if (M.find(w) == M.end())
	    S.pb(w);
	M.insert(w);
    }

    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    
    sort(S.begin(), S.end());
    
    for (int T : S) {
	bfs(T);
	bfs(T + 1);
    }


    if (min(mrk[0][n], mrk[1][n]) != INF)
	printf("%lld\n", min(mrk[0][n], mrk[1][n]));
    else puts("-1");
}


