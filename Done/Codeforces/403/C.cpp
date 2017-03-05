//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

vector<int> adj[MAX];
int color[MAX], st[MAX];
set<int> neig[MAX];
int n, mx = 1;

int avail (int u) {
    int cnt = st[u];
    set<int>::iterator it = neig[u].find(st[u]);

    for (;it != neig[u].end(); ++it) {
	int x = *it;
	if (x != cnt) break;
	else cnt++;
    }
    st[u] = cnt;
    mx = max(mx, cnt);
    return cnt;
}

void dfs (int u, int dad) {
    if (dad == -1) {
	color[u] = 1;
	neig[u].insert(1);
    }
    else {
	color[u] = avail(dad);
	neig[u].insert(color[u]);
	neig[dad].insert(color[u]);
    }
    for (auto v : adj[u]) {
	neig[v].insert(color[u]);
	if (!color[v]) dfs(v, u);
    }
}


int main () {
    scanf ("%d", &n);
    for (int i = 1; i < n; i++) {
	int x, y;
	scanf ("%d %d", &x, &y);
	adj[x].pb(y);
	adj[y].pb(x);
	st[i] = 1;
    }
    st[n] = 1;
    dfs(1, -1);
    printf("%d\n", mx);
    for (int i = 1; i <= n; i++)
	printf("%d ", color[i]);
    printf("\n");
}

