//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int N = 1123;
const int S = 150;
const ll INF = (ll)1e18;
const ll  MOD = 1000000007;

ll n, m, s, t, c, d;
ll p[S], g[S][S];
ll x[S], dist[S][N];
ll mrk[N], r[S][S];
ll seen[S][S];
map<ll, ll> ID;
vector<pii> adj[N];

struct node {
    ll cost, tank, cur, nxt;
    node (ll C = INF, ll T = -1, ll U = -1, ll V = -1): cost(C), tank(T), cur(U), nxt(V) {}
    node (): cost(INF), tank(-1), cur(-1), nxt(-1) {}
    
    bool operator < (const node ot) const {
	return (cost > ot.cost || (cost == ot.cost && tank < ot.tank));
    }

    bool operator == (const node ot) const {
	return (cost == ot.cost && tank == ot.tank && cur == ot.cur && nxt == ot.nxt);
    }
};


void dijkstra (ll i, ll no) {
    set<pii> Q;
    for (int k = 0; k < N; k++)
	mrk[k]= 0;
    
    dist[i][no] = 0;
    Q.insert(pii(0, no));
    while (!Q.empty()) {
	ll u = Q.begin()->second;
	mrk[u] = 1;
	for (auto e : adj[u]) {
	    ll v = e.first;
	    ll w = e.second;
	    if ((dist[i][u] + w) < dist[i][v]) {
		if (dist[i][v] != INF && mrk[v] == 0) {
		    Q.erase (pii(dist[i][v], v));
		    dist[i][v] = dist[i][u] + w;
		    Q.insert (pii(dist[i][v], v));
		} else {
		    dist[i][v] = dist[i][u] + w;		    
		    Q.insert (pii(dist[i][v], v));
		}		
	    } 
	}
	Q.erase(pii(dist[i][u], u));
    }

    for (ll j = 0; j < s; j++) {
	g[i][j] = dist[i][x[j]];
    }
    g[i][s] = dist[i][d];
    g[s][i] = dist[i][d];
}

ll solve (ll st, ll ed) {
    debug ("Solucionando para %lld %lld\n", st, ed);
    
    for (int i = 0; i < S; i++)
	for (int j = 0; j < S; j++) {
	    r[i][j] = INF;
	    seen[i][j] = 0;
	}
	    
    r[st][st] = 0;
    priority_queue<node> Q;
    Q.push(node(0, 0, st, st));

    while (!Q.empty()) {
	node A = Q.top();
	ll o = A.cur, u = A.nxt;
	ll tank = A.tank, cost = A.cost;
	Q.pop();
	if (seen[o][u]) continue;
	debug ("\nNo estado %lld %lld %lld %lld\n", cost, tank, o, u);
	seen[o][u] = 1;
	ll tam = ((ed == s) ? s : s);
	
	for (ll v = 0; v <= tam ; v++) {
	    ll w = g[v][o];
	    debug ("distancia de %lld para %lld eh %lld\n", v, o, g[v][o]);
	    if (w <= t) {		
		if (p[o] <= p[v]) {
		    debug ("        Tentando encher o tanque para %lld ", v);
		    // Se é melhor colocar gasolina na origem, encho o tanque
		    if (cost + (t - tank) * p[o] < r[v][o]) {
			r[v][o] = cost + (t - tank) * p[o];
			Q.push(node(r[v][o], t - w, v, o));
			debug (" - Relaxando %lld para %lld\n", v, r[v][o]);
		    } else debug("\n");
		} else {
		    debug ("        Tentando colocar o necessário para %lld ", v);
		    // Caso contrário coloco só o necessário
		    ll qtd = max((ll)0, w - tank);
		    if (cost + qtd * p[o] < r[v][o]) {
			r[v][o] = cost + qtd * p[o];
			Q.push(node(r[v][o], max((ll)0, tank - w), v, o));
			debug (" - Relaxando %lld para %lld\n", v, r[v][o]);
		    } else debug("\n");
		}			
	    }
	}
    }
    ll ret = INF;
    for (int i = 0; i <= s; i++) {
	ret = min(ret, r[ed][i]);
	debug ("\n");
	for (int j = 0; j <= s; j++)
	    debug ("%11lld ", r[i][j]);
    }
    debug("\n");
    return ret;
}


int main () {
    int T;
    for (scanf("%d", &T); T; T--) {

	for (int i = 0; i < S; i++)
	    for (int j = 0; j < S; j++)
		g[i][j] = INF;
	
	for (int i = 0; i < N; i++) adj[i].clear();

	for (int i = 0; i < S; i++) {
	    x[i] = 0;
	    p[i] = 0;
	}

	for (int i = 0; i < S; i++)
	    for (int j = 0; j < N; j++)
		dist[i][j] = INF;
	ID.clear();
	
	scanf ("%lld%lld%lld", &n, &m, &s);
	scanf ("%lld", &t);

	for (int i = 0; i < m; i++) {
	    ll a, b, f;
	    scanf ("%lld%lld%lld", &a, &b, &f);
	    adj[a].pb(pii(b, f));
	    adj[b].pb(pii(a, f));
	}


	for (int i = 0; i < s; i++) {
	    scanf ("%lld%lld", &x[i], &p[i]);
	    ID[x[i]] = i;
	}

	scanf ("%lld%lld", &c, &d);
	
	for (int i = 0; i < s; i++) {
	    dijkstra(i, x[i]);
	    debug ("distancias a partir de %d (%lld)\n", i, x[i]);
	    for (int j = 0; j <= s; j++)
		debug ("%lld ", g[i][j]);
	    debug("\n");
	}

	g[s][s] = 0;
	
	debug ("distancias a partir de %lld (%lld)\n", s, d);
	for (int j = 0; j <= s; j++)
	    debug ("%lld ", g[s][j]);
	debug("\n<><><><<><><><><><><>\n\n");
	
	printf ("%lld\n", solve (ID[c], (ID.find(d) == ID.end()) ? s : ID[d]));

	debug("\n\n");
    }
}



