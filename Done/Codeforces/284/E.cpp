//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int VTX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

vector<int> adj[VTX];
int n, m, tam;
int a[MAX];
map<int, vector<int> > fac[MAX];
int match[VTX];
int seen[VTX];
vector<int> test;

bool dfs (int u) {
    for (auto v : adj[u]) {
	if (!seen[v]) {
	    seen[v] = 1;
	    if (match[v] < 0 || dfs(match[v])) {
		match[v] = u;
		return true;
	    }
	}
    }
    return false;
}


int main () {
    tam = 0;
    
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
	scanf ("%d", a + i);
	int num = a[i];
	debug ("\nadding to group %d \n", i);
	for (int k = 2; k * k <= num; k++) {
	    while (num % k == 0) {
		debug ("adding %d vertex (%d)\n", tam + 1, k);
		if (i % 2) test.pb(tam);
		fac[i][k].pb (tam++);
		num /= k;
	    }
	}
	if (num != 1) {
	    debug ("adding %d vertex (%d)\n", tam + 1, num);
	    if (i % 2) test.pb(tam);
	    fac[i][num].pb (tam++);
	}
    }

    for (int i = 0; i < m; i++) {
	int x, y;
	scanf ("%d%d", &x, &y);
	
	for (auto e : fac[x]) {
	    if (fac[y][e.first].empty()) continue;
	    for (int q : e.second)
		for (int p : fac[y][e.first])
		    adj[q].pb(p), adj[p].pb(q);
	}
    }

    memset(match, -1, sizeof(match));

    int resp = 0;

    for (int i = 0; i < (int)test.size(); i++) {
	memset(seen, 0, sizeof(seen));
	if (dfs(test[i])) resp++;
    }
    
    printf ("%d\n", resp);

    return 0;
}
