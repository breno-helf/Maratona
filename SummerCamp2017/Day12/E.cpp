//This code was written by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii, char> pic;


const int MAX = 405;
const int BIG = MAX*MAX*20;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const pic UND = mp(mp(-1, -1), -1);

int n, m, q, d[112];
vector<int> adj[MAX][30];
vector<pii> rev[MAX];

char g[MAX][MAX];
pic pre[MAX][MAX][30];
int dist[MAX][MAX][30];
bool mark[MAX][MAX][30];
pic que[BIG];
char st[BIG];

void solve () {    
    int ini, fim;
    ini = fim = 0;
    for (int i = 1; i <= n; i++) {
	for (int c = 0; c <= ('z' - 'a' + 1); c++) {
	    que[fim++] = mp(mp(i, i), c);
	    mark[i][i][c] = true;
	    dist[i][i][c] = 0;
	}
    }

    while (ini < fim) {
	int u, v;
	int label;
	u = que[ini].first.first;
	v = que[ini].first.second;
	label = que[ini].second;
	ini++;

	if (label == 0) {
	    for (pii e : rev[u]) {
		int nxtU = e.first;
		int c = e.second;
		if (mark[nxtU][v][c]) continue;
		que[fim] = mp(mp(nxtU, v), c);
		fim++;
		pre[nxtU][v][c] = mp(mp(u, v), label);
		mark[nxtU][v][c] = true;
		dist[nxtU][v][c] = dist[u][v][label] + 1;
	    }
	} else {
	    for (int nxtV : adj[v][label]) {
		if (mark[u][nxtV][0]) continue;
		que[fim] = mp(mp(u, nxtV), 0);
		fim++;
		pre[u][nxtV][0] = mp(mp(u, v), label);
		mark[u][nxtV][0] = true;
		dist[u][nxtV][0] = dist[u][v][label] + 1;
	    }
	}	
    }    
}

string calc (int u, int v) {
    string ret = "";
    int last = 0;
    int Nu, Nv;
    char Nc;

    for (int i = dist[u][v][last]; i > 1; i--) {
	Nu = pre[u][v][last].first.first;
	Nv = pre[u][v][last].first.second;
	Nc = pre[u][v][last].second;
	if (Nc > 0) ret += Nc + 'a' - 1;
	u = Nu;
	v = Nv;
	last = Nc;
    }
    Nu = pre[u][v][last].first.first;
    Nv = pre[u][v][last].first.second;
    Nc = pre[u][v][last].second;

    u = Nu;
    v = Nv;
    last = Nc;

    string t = ret;
    reverse(t.begin(), t.end());


    if (last > 0) ret += last + 'a' - 1;
    ret += t;
    return ret;
}

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
	int u, v;
	char c;
	cin >> u >> v >> c;
	adj[u][c - 'a' + 1].pb(v);
	rev[v].pb(mp(u, c - 'a' + 1));
	g[u][v] = c;
    }

    solve();
    
    cin >> q;

    for (int i = 0; i < q; i++)
	cin >> d[i];

    for (int i = 1; i < q; i++) {
	if (mark[d[i - 1]][d[i]][0]) {
	    string ans = calc(d[i - 1], d[i]);
	    cout << ans.size() << ' ' << ans << '\n';
	} else cout << -1 << '\n';
    }
    return 0;
}
