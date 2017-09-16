//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
vector<int> adj[MAX];
int mode[MAX];
int mrk[MAX];
void dfs(int u, int h) {
    mrk[u] = 1;
    for (int i = 0; i < 2 * h; i++) putchar(' ');
    if (!adj[u].empty()) printf("%c ", mode[u] ? '-' : '+');
    else printf("  ");

    if (u == 0) printf("project\n");
    else printf("object%d\n", u);
    
    if (mode[u]) {
	for (int v : adj[u]) {
	    if (!mrk[v]) dfs(v, h + 1);
	}
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
	char c;
	int k;
	scanf(" %c %d", &c, &k);

	mode[i] = (c == '-') ? 1 : 0;
	
	for (int j = 0; j < k; j++) {
	    int a;
	    scanf("%d", &a);
	    adj[i].pb(a);
	}
    }
    
    dfs(0, 0);
    return 0;
}

