//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, m;
set<pll> opt;
ll c[MAX], w[MAX];
pll ans[MAX];
ll dis;

int main () {
    dis = 0;
    scanf ("%lld %lld", &n, &m);
    for (int i = 0; i < n; i++)
	scanf ("%lld", c + i);
    for (int i = 0; i < n; i++)
	scanf ("%lld", w + i);
    
    for (int i = 0; i < n; i++) {
	opt.insert(mp(w[i]*(100 - c[i] % 100), i));
	
	if (c[i] % 100 == 0) {
	    debug("1. %lld\n", i);
	    opt.erase(mp(w[i]*(100 - c[i] % 100), i));
	    ans[i] = mp(c[i]/100, 0);
	}
	else if (c[i] % 100 <= m) {
	    debug("2. cur %lld -- spend %lld\n", m, c[i] % 100);
	    m -= c[i] % 100;
	    ans[i] = mp(c[i]/100, c[i] % 100);
	} else {
	    int cur = opt.begin()->second;
	    debug("3. rem %lld -- need %lld\n", cur, c[i] % 100);
	    m += 100;
	    ans[i] = mp(c[i]/100, c[i] % 100);
	    ans[cur] = mp(c[cur]/100 + 1, 0);
	    m -= c[i] % 100;
	    dis += w[cur] * (100 - c[cur] % 100);
	    opt.erase(opt.begin());
	}
    }
    printf("%lld\n", dis);
    for (int i = 0; i < n; i++) {
	printf ("%lld %lld\n", ans[i].first, ans[i].second);	
    }
    
}

