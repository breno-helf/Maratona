//This code was written by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 42;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, deg[MAX];
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
vector<int> adj[MAX];
pii cord[MAX];

void dfs (int u, int pai, int d, int pot) {
    bool mark[4] = {false, false, false, false};
    if (d != -1) mark[d] = true;

    for (auto v : adj[u]) {
	if (v == pai) continue;
	int nxt;
	for (nxt = 0; nxt < 4; nxt++)
	    if(!mark[nxt]) break;
	mark[nxt] = true;
	
	cord[v] = pii((1<<pot) * dx[nxt] + cord[u].first, (1<<pot) * dy[nxt] + cord[u].second);
	dfs(v, u, nxt ^ 1, pot - 1); 	
    }
    
}

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
	int u, v;
	cin >> u >> v;
	adj[u].pb(v);
	adj[v].pb(u);
	deg[u]++;
	deg[v]++;
    }
    for (int i = 1; i <= n; i++)
	if (deg[i] > 4) {
	    cout << "NO" << '\n';
	    return 0;
	}
    cord[1] = {0, 0};
    dfs(1, 0, -1, 30);
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
	cout << cord[i].first << ' ' << cord[i].second << '\n';
    }
    return 0;
}
