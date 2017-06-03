//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 512345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;


ll n;
int m;
int st[MAX];
int adj[MAX][2];
int ind[MAX];
ll acc[MAX];

void dfs (int u) {
    if (u == 0) return;

    ll balls = acc[u];
  
    int v = adj[u][st[u]];

    acc[v] += (balls + 1LL) / 2LL;
    ind[v]--;

    if (!ind[v])
	dfs (v);

    v = adj[u][st[u] ^ 1];

    acc[v] += balls / 2LL;
    ind[v]--;

    if (!ind[v])
	dfs (v);
  
    if (balls % 2)
	st[u] ^= 1;
}

int main () {
    memset(acc, 0, sizeof(acc));
    
    scanf ("%lld %d", &n, &m);
  
    for (int i = 1; i <= m; i++) {
	char c;
	int L, R;
	scanf (" %c %d %d", &c, &L, &R);
	if (c == 'L') st[i] = 0;
	else st[i] = 1;
    
	ind[L]++;
	ind[R]++;
    
	adj[i][0] = L;
	adj[i][1] = R;
    }

    acc[1] = n;
    
    vector<int> top;
    for (int i = 1; i <= m; i++)
	if (!ind[i]) top.pb(i);

    for (auto u : top) {
	dfs(u);
    }
    
    for (int i = 1; i <= m; i++) {
	printf ("%c", st[i] ? 'R' : 'L');
    }
    printf("\n");
    return 0;
}


