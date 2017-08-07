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

int n, m;
int g[MAX][MAX];
int r[MAX], c[MAX];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= m; j++) {
	    scanf("%d", &g[i][j]);
	}
    }

    vector<pii> resp;

    if (n < m) {
	for (int i = 1; i <= n; i++) {
	    int cur = INF;
	    for (int j = 1; j <= m; j++) {
		cur = min(g[i][j], cur);
	    }
	    for (int j = 1; j <= m; j++) {
		g[i][j] -= cur;
	    }
	    for (int j = 1; j <= cur; j++) resp.pb(pii(i, 0));
	}

	for (int j = 1; j <= m; j++) {
	    int cur = INF;
	    for (int i = 1; i <= n; i++) {
		cur = min(cur, g[i][j]);
	    }
	    for (int i = 1; i <= n; i++) {
		g[i][j] -= cur;
	    }
	    for (int i = 1; i <= cur; i++) resp.pb(pii(j, 1));
	}
    } else {
	for (int j = 1; j <= m; j++) {
	    int cur = INF;
	    for (int i = 1; i <= n; i++) {
		cur = min(cur, g[i][j]);
	    }
	    for (int i = 1; i <= n; i++) {
		g[i][j] -= cur;
	    }
	    for (int i = 1; i <= cur; i++) resp.pb(pii(j, 1));
	}

	for (int i = 1; i <= n; i++) {
	    int cur = INF;
	    for (int j = 1; j <= m; j++) {
		cur = min(g[i][j], cur);
	    }
	    for (int j = 1; j <= m; j++) {
		g[i][j] -= cur;
	    }
	    for (int j = 1; j <= cur; j++) resp.pb(pii(i, 0));
	}
    }
    
    bool ok = true;
    for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= m; j++) {
	    if (g[i][j] != 0)
		ok = false;
	}
    }

    if (!ok) {
	puts("-1");
	return 0;
    }

    printf("%d\n", (int)resp.size());
    for (auto e : resp) {
	if (e.second == 0) printf("row %d\n", e.first);
	else printf("col %d\n", e.first);
    }
	    
    return 0;
}

