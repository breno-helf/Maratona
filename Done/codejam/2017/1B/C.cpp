//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef pair<int,ld> pii;
typedef pair<ld, pii> birl;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, q;
int mrk[MAX];
vector<pii> adj[MAX];
ld s[MAX];
ld e[MAX];
ld resp[MAX][MAX];
ld d[MAX];

int main () {
    int T;
    scanf ("%d", &T);
    for (int t = 1; t <= T; t++) {
	for (int i = 0; i < MAX; i++)
	    for (int j = 0; j < MAX; j++)
		resp[i][j] = (i == j) ? 0 : 1.0/0.0;

	for (int i = 0; i < MAX; i++) adj[i].clear();
	memset(mrk, 0, sizeof(mrk));
	
	scanf ("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
	    scanf ("%LF %LF", e + i, s + i);
	}
	
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; j++) {
		ld a;
		scanf ("%LF", &a);
		if (a != -1) {
		    adj[i].pb(pii(j, a));
		}
	    }
	}

	// Making n bfs for each horse
	for (int i = 1; i <= n; i++) {
	    set<birl> Q;
	    for (int j = 0; j < MAX; j++) d[j] = -1;
	    Q.insert(birl(0, pii(i, e[i])));
	    debug (">> %d\n", i);
	    while (!Q.empty()) {
		int u = (*Q.begin()).second.first;
		ld f = (*Q.begin()).second.second;
		mrk[u] = i;
		for (auto E : adj[u]) {
		    int v = E.first;
		    ld w = E.second;
		    debug (")))) %d %LF %LF\n", v, w, f); 
		    if (w > f) continue;
		    if (mrk[v] != i) {
			if ((resp[i][u] + w / s[i]) < resp[i][v]) {
			    if (resp[i][v] == (1.0)/(0.0)) {
				resp[i][v] = resp[i][u] + w / s[i];
				d[v] = f - w;
				Q.insert(birl(resp[i][v], pii(v, d[v])));
			    } else {
				Q.erase(birl(resp[i][v], pii(v, d[v])));
				resp[i][v] = resp[i][u] + w / s[i];
				d[v] = f - w;
				Q.insert(birl(resp[i][v], pii(v, d[v])));				    
			    }
			}
		    }
		}
		Q.erase(birl(resp[i][u], pii(u, f)));
	    }
	}

	for (int k = 1; k <= n; k++) {
	    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
		    if (resp[i][j] > (resp[i][k] + resp[k][j])) {
			resp[i][j] = resp[i][k] + resp[k][j];
		    }		    
		}		
	    }	    
	}

	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; j++) {
		debug ("%.3LF ", resp[i][j]);
	    }
	    debug ("\n");
	}
	
	printf ("Case #%d:", t); 
	
	for (int i = 0; i < q; i++) {
	    int a, b;
	    scanf ("%d %d", &a, &b);
	    printf (" %LF", resp[a][b]);
	}
	printf("\n");
    }
}

