//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
char g[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int d[MAX][MAX][4];
bool check (int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int main () {
    pii resp = pii(-1, -1);
    pii st = pii(-1, -1);
    memset(d, INF, sizeof(d));
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    scanf (" %c", &g[i][j]);
	    if (g[i][j] == 'S') st = pii(i, j);
	    if (g[i][j] == 'T') resp = pii(i, j);
	}
    }
    for (int i = 0; i < 4; i++) 
	d[st.first][st.second][i] = 0;
    
    queue< pair<int, pii> > Q;

    Q.push(mp((0), st));
    Q.push(mp((1), st));
    Q.push(mp((2), st));
    Q.push(mp((3), st));

    while (!Q.empty()) {
	pii u = Q.front().second;
	int dir = Q.front().first;
	int dist = d[u.first][u.second][dir];
	
	for (int k = 0; k < 4; k++) {
	    int ni = u.first + dx[k];
	    int nj = u.second + dy[k];
	    int nd = (k == dir) ? 0 : 1;
	    if (check(ni, nj) && g[ni][nj] != '*') {
		if (dist + nd < d[ni][nj][k]) {
		    d[ni][nj][k] = dist + nd;
		    Q.push(mp((k), pii(ni,nj)));
		}		
	    }	    
	}
	Q.pop();
    }

    // for (int i = 0; i < n; i++) {
    // 	for (int j = 0; j < m; j++) {
    // 	    debug ("%d ", d[i][j]);
    // 	}
    // 	debug ("\n");
    // }

    int p = INF;
    for (int k = 0; k < 4; k++) p = min(p, d[resp.first][resp.second][k]);
    
    printf ("%s\n", (p <= 2) ? "YES" : "NO");
    return 0;
}

