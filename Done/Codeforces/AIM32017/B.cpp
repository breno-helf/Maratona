//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 52;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
int g[MAX][MAX];
ll r[MAX], c[MAX];
ll resp = 0;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    scanf("%d", &g[i][j]);
	    r[i] += g[i][j];
	    c[j] += g[i][j];
	}
    }
    resp = 0;

    for (int i = 0; i < n; i++) {
	ll b = r[i], w = m - r[i];
	b = (1LL<<b) - 1;
	w = (1LL<<w) - 1;
	resp += b + w;
    }
    
    for (int i = 0; i < m; i++) {
	ll b = c[i], w = n - c[i];
	b = (1LL<<b) - 1;
	w = (1LL<<w) - 1;
	resp += b + w;
    }

    resp -= (ll)n * (ll)m;

    printf("%lld\n", resp);
    return 0;
}

