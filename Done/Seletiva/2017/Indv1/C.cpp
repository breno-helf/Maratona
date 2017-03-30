//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii, int> ptr;

const int MAX = 512;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int main () {
    int t;
    scanf("%d", &t);
    for (int c = 0; c < t; c++) {
	int n, f, m, cnt = 1;	
	vector<int> nodes[MAX];
	vector<int> flo;
	set<int> all;
	vector<pii> adj[MAX];
	map<pii, int> code;
	map<int, pii> inv;
	int dist[MAX][MAX];
	memset(dist, INF, sizeof(dist));
	
	scanf("%d%d%d", &n, &f, &m);
	for (int i = 1; i < n; i++) {
	    if (code[pii(i, 1)] == 0) {
		code[pii(i, 1)] = cnt++;
		inv[cnt - 1] = pii(i, 1);
	    }
	    if (code[pii(i + 1, 1)] == 0) {
		code[pii(i + 1, 1)] = cnt++;
		inv[cnt - 1] = pii(i + 1, 1);
	    }
	    adj[code[pii(i, 1)]].pb(mp(code[pii(i + 1, 1)], 1));
	    adj[code[pii(i + 1, 1)]].pb(mp(code[pii(i, 1)], 1));
	    dist[code[pii(i, 1)]][code[pii(i + 1, 1)]] = 1;
	    dist[code[pii(i + 1, 1)]][code[pii(i, 1)]] = 1;
	    all.insert(code[pii(i, 1)]);
	    nodes[i].pb(1);
	}
	if (code[pii(1, 1)] == 0) {
	    code[pii(1, 1)] = cnt++;
	    inv[cnt - 1] = pii(1, 1);
	}
	if (code[pii(n, 1)] == 0) {
	    code[pii(n, 1)] = cnt++;
	    inv[cnt - 1] = pii(n, 1);
	}
	adj[code[pii(n, 1)]].pb(mp(code[pii(1, 1)], 1));
	adj[code[pii(1, 1)]].pb(mp(code[pii(n, 1)], 1));
	dist[code[pii(1, 1)]][code[pii(n, 1)]] = 1;
	dist[code[pii(n, 1)]][code[pii(1, 1)]] = 1;
	all.insert(code[pii(n, 1)]);
	
	nodes[n].pb(1);
	for (int i = 0; i < m; i++) {
	    int x, y, w, z, p;
	    scanf("%d%d%d%d%d", &x, &y, &w, &z, &p);
	    nodes[x].pb(y);
	    nodes[w].pb(z);

	    if (code[pii(x, y)] == 0) {
		code[pii(x, y)] = cnt++;
		inv[cnt - 1] = pii(x, y);
	    }
	    if (code[pii(w, z)] == 0) {
		code[pii(w, z)] = cnt++;
		inv[cnt - 1] = pii(w, z);
	    }
	    dist[code[pii(x, y)]][code[pii(w, z)]] = p;
	    dist[code[pii(w, z)]][code[pii(x, y)]] = p;
	    all.insert(code[pii(x, y)]);
	    all.insert(code[pii(w, z)]);	    
	    adj[code[pii(x, y)]].pb(mp(code[pii(w, z)], p));
	    adj[code[pii(w, z)]].pb(mp(code[pii(x, y)], p));
	}
	for (int i = 1; i <= n; i++) sort(nodes[i].begin(), nodes[i].end());
	for (int a : all) flo.pb(a);

	int tam = flo.size();
	// Floyd

	for (int i = 0; i < tam; i++) {
	    for (int j = i + 1; j < tam; j++) {
		if (i == j) continue;

		if (dist[flo[i]][flo[j]] == 0) {
		    if (inv[flo[i]].first == inv[flo[j]].first)
			dist[flo[i]][flo[j]] = abs(inv[flo[i]].second - inv[flo[j]].second);
		    else
			dist[flo[i]][flo[j]] = INF;
		}
		else {
		    if (inv[flo[i]].first == inv[flo[j]].first)
			dist[flo[i]][flo[j]] = min(dist[flo[i]][flo[j]], abs(inv[flo[i]].second - inv[flo[j]].second));
		}
		if (dist[flo[j]][flo[i]] == 0) {
		    if (inv[flo[i]].first == inv[flo[j]].first)
			dist[flo[j]][flo[i]] = abs(inv[flo[j]].second - inv[flo[i]].second);
		    else
			dist[flo[j]][flo[i]] = INF;
		}
		else {
		    if (inv[flo[i]].first == inv[flo[j]].first)
			dist[flo[j]][flo[i]] = min(dist[flo[j]][flo[i]], abs(inv[flo[i]].second - inv[flo[j]].second));
		}
	    }
	}
	for (int k = 0; k < tam; k++) {
	    for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
		    if (dist[flo[i]][flo[j]] > (dist[flo[i]][flo[k]] + dist[flo[k]][flo[j]]))
			dist[flo[i]][flo[j]] = (dist[flo[i]][flo[k]] + dist[flo[k]][flo[j]]);
		}
	    }
	}
	
	int q;
	scanf("%d", &q);
	for (int a = 0; a < q; a++) {
	    int x, y, w, z;
	    scanf("%d%d%d%d", &x, &y, &w, &z);
	    int resp = INF;
	    if (w == x) resp = abs(y - z);

	    int optA[] = {-1, -1};
	    int optB[] = {-1, -1};
	    auto PTR = lower_bound(nodes[x].begin(), nodes[x].end(), y);
	    if (PTR != nodes[x].end()) optA[0] = *PTR;
	    if (PTR != nodes[x].begin()) optA[1] = *prev(PTR);

	    PTR = lower_bound(nodes[w].begin(), nodes[w].end(), z);
	    if (PTR != nodes[w].end()) optB[0] = *PTR;
	    if (PTR != nodes[w].begin()) optB[1] = *prev(PTR);

	    for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		    if (optA[i] != -1 && optB[j] != -1)
			resp = min(resp, abs(y - optA[i]) + abs(z - optB[j]) + dist[code[pii(x, optA[i])]][code[pii(w, optB[j])]]);
	    
	    printf("%d\n", resp);
	}
    }
    return 0;
}

