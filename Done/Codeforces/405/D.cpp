//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, k, cnt;
ll sum = 0, jmp[MAX][7];
vector<int> adj[MAX];
bool mrk[MAX];

ll calc (ll a, ll b) {
    return ((a - b) % k + k) % k;
}

void dfs(int u, int h) {
    int ini = cnt;
    mrk[u] = true;
    jmp[u][h % k] = 1;
    for (auto v : adj[u]) {
	if (!mrk[v]) {
	    dfs(v, h + 1);
	    for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
		    sum += (calc(k, calc(i + j, 2 * h)))
			* jmp[u][i] * jmp[v][j];
		}
	    }
	    for (int i = 0; i < k; i++)
		jmp[u][i] += jmp[v][i];
	}
    }
    sum += (cnt - ini + 1) * (n - (cnt - ini + 1));
    cnt++;
}

int main () {
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i < n; i++) {
	int a, b;
	scanf("%d%d", &a, &b);
	adj[a].pb(b);
	adj[b].pb(a);
    }
    cnt = 0;
    dfs(1, 0);
    printf("%lld\n", sum / k);
    return 0;
}

