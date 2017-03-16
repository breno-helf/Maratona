//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;

set<pii> c, p, C, P;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	int l, r;
	scanf("%d%d", &l, &r);
	c.insert(pii(l, r));
	C.insert(pii(r, l));
    }
    int ans = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
	int l, r;
	scanf("%d%d", &l, &r);
	if (c.upper_bound(pii(r, 0)) != c.end()) {
	    debug("dist entre %d %d e %d %d eh ", l, r, prev(c.end())->first, prev(c.end())->second);
	    debug("%d\n", prev(c.end())->first - r);
	    ans = max(ans, prev(c.end())->first - r);
	}
	
	if (C.lower_bound(pii(l, 0)) != C.begin()) {
	    debug("dist entre %d %d e %d %d eh ", l, r, C.begin()->second, C.begin()->first);
	    debug("%d\n", l - C.begin()->first);

	    ans = max(ans, l - C.begin()->first);
	}
	p.insert(pii(l, r));
	P.insert(pii(r, l));
    }
    printf("%d\n", ans);
    return 0;
}
