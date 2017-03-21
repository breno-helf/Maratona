//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 512;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
ll resp = 0;
bitset<MAX> P[64][MAX], B[64][MAX];

int main () {
    scanf ("%d%d", &n, &m);
    
    for (int i = 0; i < m; i++) {
	int u, v, t;
	scanf ("%d%d%d", &u, &v, &t);

	if (!t)
	    P[0][u][v] = 1;
	else
	    B[0][u][v] = 1;
    }
    
    for (int k = 1; k <= 60; k++) {
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; j++) {
		if (P[k - 1][i][j]) P[k][i] |= B[k - 1][j];
		if (B[k - 1][i][j]) B[k][i] |= P[k - 1][j];
	    }
	}	
    }

    set<int> cur;
    cur.insert(1);
    int par = 0;
    for (int k = 60; k >= 0; k--) {
	set<int> nxt;

	if (par % 2) {
	    for (auto i : cur)
		for (int j = 1; j <= n; j++)
		    if (B[k][i][j]) nxt.insert(j);
	} else {
	    for (auto i : cur)
		for (int j = 1; j <= n; j++)
		    if (P[k][i][j]) nxt.insert(j);
	}

	if (!nxt.empty()) {
	    par ^= 1;
	    cur = nxt;
	    resp += (1LL << k);
	}
    }

    if (resp > (ll)1e18) puts("-1");
    else printf("%lld\n", resp);
    return 0; 
}

