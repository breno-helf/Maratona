//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii, pii> PAR;

const int MAX = 30;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int R, c;
char g[MAX][MAX];

bool check (int i, int j) {
    return (i >= 1 && i <= R && j >= 1 && j <= c);
}

pii expand (pii a, pii b, bool d) {
    if (d == false) {
	int l, r;
	int i = a.first, j = a.second;
	
	for (l = j - 1; l > 0; l--) {
	    if (g[i][l] != '?') break;
	    g[i][l] = g[i][j];
	}
	
	for (r = j + 1; r <= c; r++) {
	    if (g[i][r] != '?') break;
	    g[i][r] = g[i][j];
	}

	//debug ("Expandi %c horizontalmente para %d %d\n", g[i][j], l, r);
	
	return pii(l + 1, r - 1);
    } else {
	int x = a.first;
	int l = a.second, r = b.second;
	int i;

	for (i = x - 1; i > 0; i--) {
	    bool ok = true;
	    for (int k = l; k <= r; k++) {
		if (g[i][k] != '?') ok = false;
	    }
	    if (!ok) break;
	    for (int k = l; k <= r; k++)
		g[i][k] = g[x][l];
	}
	
	for (i = x + 1; i <= R; i++) {
	    bool ok = true;
	    for (int k = l; k <= r; k++) {
		if (g[i][k] != '?') ok = false;
	    }
	    if (!ok) break;
	    for (int k = l; k <= r; k++)
		g[i][k] = g[x][l];
	}

	return pii(-1, -1);
    }
}

int main () {
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++) {
	memset(g, '?', sizeof(g));
	cin >> R >> c;
	vector<pii> kid;
	vector<PAR> lag;
	
	for (int i = 1; i <= R; i++) {
	    for (int j = 1; j <= c; j++) {
		cin >> g[i][j];
		if (g[i][j] != '?') kid.pb(pii(i, j));
	    }
	}
	
	for (auto &e : kid) {
	    pii a = (expand(e, e, false));
	    lag.pb(mp(pii(e.first, a.first), pii(e.first, a.second)));
	}
	
	for (auto &e : lag) {
	    expand (e.first, e.second, true);
	}

	cout << "Case #" << T << ":\n";
	
	for (int i = 1; i <= R; i++) {
	    for (int j = 1; j <= c; j++) {
		cout << g[i][j];
	    }
	    cout << '\n';
	}
    }
}

